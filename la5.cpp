#include <fstream>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <cstdlib>
#include <pthread.h>
using namespace std;
void * thread_func(void *);
int main()
{
    setlocale(LC_ALL, "rus");
	string s;
	int i=0,j=0, q = 0;
	int k, status,t=-1;
	ifstream ifs ("/home/danil/123.txt");
    while(getline(ifs, s))
    {
        ++q;
    }
    pthread_t tid[q]; //thread array
    string s_a[q];
    ifs.close();
    ifstream ifs1 ("/home/danil/123.txt");
    for(i=0; i<q; ++i)
    {
        getline(ifs1, s_a[i]);
    }
	for(i=0; i<q; ++i)
	{
		status=pthread_create(&tid[i], NULL, thread_func, (void *)&s_a[i]);
        if(status!=0)
            cout << "It doesn't work!\n";
	}
    void *a=NULL;// указатель на возратное значения потока
    string *b=NULL;// перевод а в стринг
    for(i=0; i<q; ++i)
    {
        pthread_join(tid[i], &a);
        b=(string *)a;
        if(*b=="0")
            ++j;
    }
    cout<< j << endl;
	ifs1.close();
	return (0);
}
void * thread_func(void *s)
{
    setlocale(LC_ALL, "Russian");
    string *s1=(string *)s;// функция принимает указатель на войд поэтому нужно типизировать к стрингам
    cout << *s1 << endl;
    string s12 = "витамин";
    cout << "Что ищем: " << s12 << endl << endl;
    //sleep(3);
    if (s1->find(s12)<=s1->length())
    {
        cout << "подстрока входит\n\n";
        s1[0]='0';
        return (s);
    }
    else
    {
        cout << "подстрока Не входит\n\n";
        s1[0]='1';
        return (s);
    }
}
