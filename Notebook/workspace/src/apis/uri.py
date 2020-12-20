import requests
from bs4 import BeautifulSoup

class Uri:
    def __init__(self, problem):
        """
        :param problemData: list of tuples -> tuple[0]: input, tuple[1]: input
        """
        self._url = 'https://www.urionlinejudge.com.br/repository/UOJ_{}.html'.format(problem)
        self._page = requests.get(self._url)
        self._html = BeautifulSoup(self._page.content, 'html.parser')

        self._problemData = self._get_test_cases() 
        self._problemName = '{} - {}'.format(problem, self._get_problem_name())

    @property
    def problemData(self):
        # Input[0] / Output[1]
        return self._problemData
    
    @property
    def problemName(self):
        return self._problemName

    def _get_test_cases(self):
        testCases = []
        content = self._html.find_all('td')
        for i in range(2, len(content), 2):
            testCases.append(
                (self._parser(content[i].text), self._parser(content[i+1].text))
            )
        return testCases
    
    def _get_problem_name(self):
        content = self._html.find_all('h1')
        return content[0].text

    def _parser(self, string):
        return '\n'.join([s.strip() for s in string.strip().split('\n')])