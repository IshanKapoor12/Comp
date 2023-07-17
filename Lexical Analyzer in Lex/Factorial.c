#include <stdio.h>

int main(){
	int n, fact;
	scanf("%d",&n);
	int i=1;
	while(i<=n){
		fact = fact*i;
		i++;
	}
	printf("%d", fact);
}

