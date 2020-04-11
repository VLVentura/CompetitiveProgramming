#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(char *str){
	bool _is_palindrome_{true};
	char *init = str, *last = &str[strlen(str)] - 1;

	while(init < last && _is_palindrome_){
		if(*init != *last) _is_palindrome_ = false;
		++init;
		--last;
	}

	return _is_palindrome_;
}

int main(){
	
	char hours[3], minutes[3], result[50], test_palindrome[50];
	bool flag{true};
	int n{0}, h, m;

	scanf("%d ", &n);
	while(n--){
		scanf("%s:%s", hours, minutes);

		h = atoi(hours);
		m = atoi(minutes);

		do{

			m == 59 ? ++h, m = 0 : ++m;
			if(h == 24) h = 0;

			if(h == 0 && m == 0){
				sprintf(result, "00:00");
				flag = true;
			} else{

				if(h == 0) {
					sprintf(test_palindrome, "%d", m);
					flag = is_palindrome(test_palindrome);

					if(flag && m < 10) sprintf(result, "0%d:0%d", h, m);
					else if(flag) sprintf(result, "0%d:%d", h, m);

				} else if(h < 10) {

					if(m >= 0 && m < 10) {
						sprintf(test_palindrome, "%d0%d", h, m);
						flag = is_palindrome(test_palindrome);

						if(flag) sprintf(result, "0%d:0%d", h, m);
					} else{
						sprintf(test_palindrome, "%d%d", h, m);
						flag = is_palindrome(test_palindrome);

						if(flag) sprintf(result, "0%d:%d", h, m);
					}

				} else {

					if(m < 10){
						sprintf(test_palindrome, "%d0%d", h, m);
						flag = is_palindrome(test_palindrome);

						if(flag) sprintf(result, "%d:0%d", h, m);
					} else{
						sprintf(test_palindrome, "%d%d", h, m);
						flag = is_palindrome(test_palindrome);

						if(flag) sprintf(result, "%d:%d", h, m);
					}
				}
			}
		}while(!flag);

		printf("%s\n", result);
	}

	return 0;
}