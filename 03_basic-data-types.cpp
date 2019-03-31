// https://hackerrank-challenge-pdfs.s3.amazonaws.com/12103-cpp-input-and-output-English?AWSAccessKeyId=AKIAJ4WZFDFQTZRGO3QA&Expires=1554056043&Signature=JMdIwD9t3wFbuWLczVwwXpp8onQ%3D&response-content-disposition=inline%3B%20filename%3Dcpp-input-and-output-English.pdf&response-content-type=application%2Fpdf

// 3 basic data types problem

#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int a;
	long b;
	char c;
	float d;
	double e;
	scanf("%d %ld %c %f %lf", &a, &b, &c, &d, &e );
	printf("%d\n%ld\n%c\n%0.3f\n%0.9lf\n", a, b, c, d, e );
	return 0;
}
