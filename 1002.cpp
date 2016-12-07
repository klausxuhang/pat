#include <iostream>
using namespace std;

typedef struct polynomial {
	double coef;
	int exp;
	polynomial* next;
}polynomial,* ppoly;
void printpoly(ppoly P);
ppoly sumpoly(ppoly p1, ppoly p2);
ppoly readpoly();
int main()
{
	ppoly p1, p2, ps;

	p1 = readpoly();
	p2 = readpoly();
	ps = sumpoly(p1, p2);
	printpoly(ps);

	return 0;
}

ppoly readpoly() {
	ppoly P, temp,pre;
	int n;
	cin >> n;
	P = new polynomial;
	P->next = NULL;
	pre = P;
	while (n--) {
		temp = new polynomial;
		cin >> temp->exp;
		cin >> temp->coef;
		temp->next = NULL;
		pre->next = temp;
		pre = temp;
		pre->next = NULL;
	}
	return P;
}

ppoly sumpoly(ppoly p1, ppoly p2) {
	ppoly pa, pb,P,pre;
	P = new polynomial;
	P->exp = 0;
	P->next = NULL;
	pre = P;
	pa = p1->next;
	pb = p2->next;
	while (pa != NULL && pb != NULL) {
		if (pa->exp == pb->exp) {
			double coefsum = pa->coef + pb->coef;
			if (coefsum == 0) {
				pa = pa->next;
				pb = pb->next;
			}
			else {
				pa->coef = coefsum;
				pre->next = pa;
				pre = pa;
				pa = pa->next;
				pre->next = NULL;
				pb = pb->next;
			}
		}else if (pa->exp > pb->exp) {
			pre->next = pa;
			pre = pa;
			pa = pa->next;
			pre->next = NULL;
		}
		else {
			pre->next = pb;
			pre = pb;
			pb = pb->next;
			pre->next = NULL;
		}
	}
	if (pa)
		pre->next = pa;
	if (pb)
		pre->next = pb;
	return P;
}

void printpoly(ppoly P) {
	int sum = 0;
	ppoly pre;
	pre = P;
	while (pre->next) {
		++sum;
		pre = pre->next;
	}
	if(sum == 0){
		cout << sum;
	}else
	cout<<sum<<' ';
	ppoly data = P->next;
	while (data) {
		printf("%d %0.1f", data->exp, data->coef);
		if (data->next)
			cout << ' ';
		data = data->next;
	}
}