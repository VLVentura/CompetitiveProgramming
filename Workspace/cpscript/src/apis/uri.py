import requests
from bs4 import BeautifulSoup

import src.util.utils as util


class Uri:
    def __init__(self, problem):
        """
        :param problem_data: list of tuples -> tuple[0]: input, tuple[1]: input
        """
        self._url = 'https://www.urionlinejudge.com.br/repository/UOJ_{}.html'.format(problem)
        self._page = requests.get(self._url)
        self._html = BeautifulSoup(self._page.content, 'html.parser')

        self._problem_data = self._get_test_cases(problem)
        self._problem_name = '{} - {}'.format(problem, self._get_problem_name())

    @property
    def problem_data(self):
        # Input[0] / Output[1]
        return self._problem_data

    @property
    def problem_name(self):
        return self._problem_name

    def _get_test_cases(self, problem):
        test_cases = []
        content = self._html.find_all('td')
        for i in range(2, len(content), 2):
            test_cases.append(
                (self._parser(content[i].text), self._parser(content[i + 1].text, add_new_line=True))
            )
        self._add_test_cases_from_udebug(test_cases, problem)
        return test_cases

    def _get_problem_name(self):
        content = self._html.find_all('h1')
        return content[0].text

    def _parser(self, string, add_new_line=False):
        string = '\n'.join([s.strip() for s in string.strip().split('\n')])
        if add_new_line:
            string += '\n'
        return string

    def _add_test_cases_from_udebug(self, test_cases, problem):
        authorization = {'authorization': util.get_authorization_code()}
        for case in self._get_problems_ids(authorization, problem):
            input_data = requests.get(
                'https://www.udebug.com/input_api/input/retrieve.json?input_id={}'.format(case),
                headers=authorization
            )
            output_data = requests.get(
                'https://www.udebug.com/output_api/output/retrieve.json?input_id={}'.format(case),
                headers=authorization
            )
            test_cases.append(
                (input_data.json()[0].replace('\r', ''), output_data.json()[0].replace('\r', ''))
            )

    def _get_problems_ids(self, authorization, problem):
        self._response = requests.get(
            'https://www.udebug.com/input_api/input_list/retrieve.json?judge_alias=URI&problem_id={}'.format(problem),
            headers=authorization
        )

        ids = []
        for item in self._response.json():
            ids.append(item['id'])

        return ids
