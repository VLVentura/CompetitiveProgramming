import requests
from bs4 import BeautifulSoup


class Uri:
    def __init__(self, problem):
        """
        :param problem_data: list of tuples -> tuple[0]: input, tuple[1]: input
        """
        self._url = 'https://www.urionlinejudge.com.br/repository/UOJ_{}.html'.format(problem)
        self._page = requests.get(self._url)
        self._html = BeautifulSoup(self._page.content, 'html.parser')

        self._problem_data = self._get_test_cases()
        self._problem_name = '{} - {}'.format(problem, self._get_problem_name())

    @property
    def problem_data(self):
        # Input[0] / Output[1]
        return self._problem_data

    @property
    def problem_name(self):
        return self._problem_name

    def _get_test_cases(self):
        test_cases = []
        content = self._html.find_all('td')
        for i in range(2, len(content), 2):
            test_cases.append(
                (self._parser(content[i].text), self._parser(content[i + 1].text))
            )
        return test_cases

    def _get_problem_name(self):
        content = self._html.find_all('h1')
        return content[0].text

    def _parser(self, string):
        return '\n'.join([s.strip() for s in string.strip().split('\n')])
