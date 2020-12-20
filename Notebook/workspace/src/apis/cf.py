import re
import requests
from bs4 import BeautifulSoup


class Cf:
    def __init__(self, problem: str):
        """
        :return param problemData: list of tuples -> tuple[0]: input, tuple[1]: input
        """
        self._problem = self._parser_problem(problem)
        self._url = 'https://codeforces.com/problemset/problem/{}/{}'.format(self._problem[0], self._problem[1])
        self._page = requests.get(self._url)
        self._html = BeautifulSoup(self._page.content, 'html.parser')

        self._problemData = self._get_test_cases()
        self._problemName = '{} - {}'.format(problem, self._get_problem_name())

    @property
    def problemData(self):
        return self._problemData

    @property
    def problemName(self):
        return self._problemName

    def _get_test_cases(self):
        testCases = []
        testInput = self._html.find_all('div', {'class': 'input'})
        testOutput = self._html.find_all('div', {'class': 'output'})
        for i in range(len(testInput)):
            testCases.append(
                (self._parser(testInput[i], 'Input'), self._parser(testOutput[i], 'Output'))
            )
        return testCases

    def _get_problem_name(self):
        content = self._html.find_all('div', {'class': 'title'})
        return content[0].text.split('.')[1].strip()

    def _parser(self, content, parse):
        content = str(content).replace('<br/>', '\n').replace(parse, '')
        content = BeautifulSoup(content, 'html.parser').text
        return '\n'.join([s.strip() for s in content.strip().split('\n')])

    def _parser_problem(self, problem):
        return re.match(r'([0-9]+)([a-zA-Z]+)', problem).groups()
