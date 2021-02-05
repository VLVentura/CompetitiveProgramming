import re
import requests
from bs4 import BeautifulSoup


class Cf:
    def __init__(self, problem: str):
        """
        :return param problem_data: list of tuples -> tuple[0]: input, tuple[1]: input
        """
        self._problem = self._parser_problem(problem)
        self._url = 'https://codeforces.com/problemset/problem/{}/{}'.format(self._problem[0], self._problem[1])
        self._page = requests.get(self._url)
        self._html = BeautifulSoup(self._page.content, 'html.parser')

        self._problem_data = self._get_test_cases()
        self._problem_name = '{} - {}'.format(problem, self._get_problem_name())

    @property
    def problem_data(self):
        return self._problem_data

    @property
    def problem_name(self):
        return self._problem_name

    def _get_test_cases(self):
        test_cases = []
        test_input = self._html.find_all('div', {'class': 'input'})
        test_output = self._html.find_all('div', {'class': 'output'})
        for i in range(len(test_input)):
            test_cases.append(
                (self._parser(test_input[i], 'Input'), self._parser(test_output[i], 'Output', add_new_line=True))
            )
        return test_cases

    def _get_problem_name(self):
        content = self._html.find_all('div', {'class': 'title'})
        return content[0].text.split('.')[1].strip()

    def _parser(self, content, parse, add_new_line=False):
        content = str(content).replace('<br/>', '\n').replace(parse, '')
        content = BeautifulSoup(content, 'html.parser').text
        content = '\n'.join([s.strip() for s in content.strip().split('\n')])
        if add_new_line:
            content += '\n'
        return content

    def _parser_problem(self, problem):
        return re.match(r'([0-9]+)([a-zA-Z]+)', problem).groups()
