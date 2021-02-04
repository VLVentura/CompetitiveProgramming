import requests
from bs4 import BeautifulSoup

import src.util.utils as util


class Uva:
    def __init__(self, problem):
        self._code = util.get_authorization_code()
        self._authorization = {'authorization': self._code}
        self._problem_data = self._get_test_cases(problem)
        self._problem_name = '{} - {}'.format(problem, self._get_problem_name(problem))

    @property
    def problem_data(self):
        return self._problem_data

    @property
    def problem_name(self):
        return self._problem_name

    def _get_problems_ids(self, problem):
        self._response = requests.get(
            'https://www.udebug.com/input_api/input_list/retrieve.json?judge_alias=UVa&problem_id={}'.format(problem),
            headers=self._authorization
        )

        ids = []
        for item in self._response.json():
            ids.append(item['id'])

        return ids

    def _get_test_cases(self, problem):
        test_cases = []
        for case in self._get_problems_ids(problem):
            input_data = requests.get(
                'https://www.udebug.com/input_api/input/retrieve.json?input_id={}'.format(case),
                headers=self._authorization
            )
            output_data = requests.get(
                'https://www.udebug.com/output_api/output/retrieve.json?input_id={}'.format(case),
                headers=self._authorization
            )
            test_cases.append((input_data.json()[0], output_data.json()[0]))

        return test_cases

    def _get_problem_name(self, problem):
        url = 'https://www.udebug.com/UVa/{}'.format(problem)
        page = requests.get(url)
        html = BeautifulSoup(page.content, 'html.parser')
        name = html.find_all('h1', {'class': 'unflag-problem-title problem-title'})
        return name[0].text
