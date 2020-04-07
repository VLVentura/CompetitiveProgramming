#include <bits/stdc++.h>

using namespace std;

int main(){

	size_t H{0}, U{0}, D{0}, F{0};

	while(scanf(" %ld %ld %ld %ld", &H, &U, &D, &F), H){

		double fatiga{U * (F/100.0)};
		double willClimb{U - fatiga}, climbedDistance = U;
		size_t days{0};

		while(climbedDistance <= H && climbedDistance >= 0){
			if(days == 0){
				if(climbedDistance <= H) climbedDistance -= D;
			} else{
				if(willClimb > 0){
					climbedDistance += willClimb;
					willClimb -= fatiga;
				}
				if(climbedDistance <= H) climbedDistance -= D;
			}
			++days;
		}
		//when he didn't even got the chance to fail
		days == 0 ? ++days : days = days;
		climbedDistance > H ? printf("success on day %ld\n", days) : printf("failure on day %ld\n", days);
	}
	
	return 0;
}