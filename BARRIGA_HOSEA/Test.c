#include <stdio.h>
#include <string.h>
#include "Exercise1.h"
#include <stdlib.h>

#include "Person.h"
#include "CircularArrayQ.h"

void newPerson(Person *p, char *x);
void funcSAL(PersonStaticArrayList *SAL, Person *p, char *x);
void funcDAL(PersonDynamicArrayList *SAL, Person *p, char *x);
void funcLL(PersonLinkedList *list, Person *p, char *x);
void funcCBL(VSpace *vs, PersonCusorBasedList *list, Person *p, char y[]);
void funcCAQ(CircularArrayQueue *list, Person* p, char *x, PersonLinkedList LL, PersonDynamicArrayList DAL);

int main(void) 
{
	char x[2] = "A";
	Person p = createPerson("", 'M', "");
	PersonStaticArrayList SAL;
    PersonDynamicArrayList DAL, DAL2;
    PersonLinkedList LL = NULL, QLL = NULL;
    PersonCusorBasedList CBL;
    VSpace VS;
    CircularArrayQueue CAQ;
    
    PersonLinkedList FList;
    PersonDynamicArrayList MList;
    
    funcSAL(&SAL, &p, x);
    funcDAL(&DAL, &p, x);
    funcLL(&LL, &p, x);
    funcCBL(&VS, &CBL, &p, x);
    funcCAQ(&CAQ, &p, x, QLL, DAL2);
    
    return 0;
}

void funcCBL(VSpace *vs, PersonCusorBasedList *list, Person *p, char y[]){
	int x;
	init_vspace(vs);
	
	for(x=0; x<8;x++){
		newPerson(p, y);
		insert_first_CBL(vs, list, *p);
		newPerson(p, y);
		insert_last_CBL(vs, list, *p);
	}
	
	display_CBL(*vs, *list);
	printf("\nINSERT\n");
	system("pause");
	system("CLS");
	
	for(x=0; x<3;x++){
		newPerson(p, y);
		insert_at_CBL(vs, list, *p, 3);
	}
	
	display_CBL(*vs, *list);
	printf("\nINSERT AT 3rd place x3\n");
	system("pause");
	system("CLS");
	
	for(x=0; x<3;x++){
		delete_first_CBL(vs, list);
		delete_last_CBL(vs, list);
	}
	
	display_CBL(*vs, *list);
	printf("\nDELETE FIRST LAST x3\n");
	system("pause");
	system("CLS");
	
//	delete_by_sex_CBL(vs,list,'F');
//	
//	display_CBL(*vs, *list);
//	printf("\nDELETE ALL FEMALE\n");
//	system("pause");
//	system("CLS");
}

void funcCAQ(CircularArrayQueue *list, Person *p, char* y, PersonLinkedList LL, PersonDynamicArrayList DAL){
	int x;
	init_array_queue(list);
	
	for(x=0;x<28;x++){
		newPerson(p, y);
		enqueue(list, *p);
	}
	
	displayQueue(list);
	printf("\nENQUEUE\n");
	system("pause");
	system("CLS");
	
	for(x=0;x<2;x++){
		dequeue(list);
	}
	
	displayQueue(list);
	printf("\nDEQUEUE 2\n");
	system("pause");
	system("CLS");
	
	LL = get_all_females(*list);
	
	display_LL(LL);
	printf("\nDISPLAY FEMALES WITH LINKED LIST\n");
	system("pause");
	system("CLS");
	
	DAL = remove_all_males(list);
	
	displayQueue(list);
	printf("\nDEQUEUE ALL MALES\n");
	system("pause");
	system("CLS");
	
	display_DAL(DAL);
	printf("\nSTORE MALES INTO DYNAMIC ARRAY LIST\n");
	system("pause");
	system("CLS");
}

void newPerson(Person *p, char *x){
	if(p->sex=='M' && (*x-65)%5 != 0){
		p->sex='F';
	}else{
		p->sex='M';
	}
	strcpy(p->name, "Astolfo ");
	strcpy(p->city, "Throne of Heroes ");
	strcat(p->name, x);
	strcat(p->city, x);
	*x = ((*x-64) % 22) + 65;
}


void funcSAL(PersonStaticArrayList *list, Person *p, char *y){
	int x;
	init_SAL(list);
	
	for(x=0;x<7;x++){
		newPerson(p, y);
		insert_first_SAL(list, *p);
		newPerson(p, y);
		insert_last_SAL(list, *p);
		newPerson(p, y);
		insert_at_SAL(list, *p, x+2);
	}
	
	display_SAL(*list);
	printf("\nINSERT\n");
	system("pause");
	system("CLS");
	
	delete_first_SAL(list);
	delete_last_SAL(list);
	
	display_SAL(*list);
	printf("\nDELETE FIRST LAST\n");
	system("pause");
	system("CLS");
	
	delete_by_sex_SAL(list,  'M');
	
	display_SAL(*list);
	printf("\nDELETE ALL MALE\n");
	system("pause");
	system("CLS");
}

void funcDAL(PersonDynamicArrayList *list, Person *p, char *y){
	int x;
	init_DAL(list);
	
	*y = 'A';
	
	for(x=0;x<9;x++){
		newPerson(p, y);
		insert_first_DAL(list, *p);
		newPerson(p, y);
		insert_last_DAL(list, *p);
		newPerson(p, y);
		insert_at_DAL(list, *p, x+2);
	}
	
	display_DAL(*list);
	printf("\nINSERT\n");
	system("pause");
	system("CLS");
	
	for(x=0; x<6; x++){
		delete_first_DAL(list);
		delete_last_DAL(list);
	}
	
	display_DAL(*list);
	printf("\nDELETE FIRST LAST x5\n");
	system("pause");
	system("CLS");
	
	delete_by_city_DAL(list,"Throne of Heroes F");
	delete_by_city_DAL(list,"Throne of Heroes A");
	delete_by_city_DAL(list,"Throne of Heroes H");
	
	display_DAL(*list);
	printf("\nDELETE CITY FAH\n");
	system("pause");
	system("CLS");
}

void funcLL(PersonLinkedList *list, Person *p, char y[]){
	int x;
	
	for(x=0;x<6;x++){
		newPerson(p, y);
		insert_first_LL(list, *p);
		newPerson(p, y);
		insert_last_LL(list, *p);
	}
	
	display_LL(*list);
	printf("\nINSERT LL\n");
	system("pause");
	system("CLS");
	
	for(x=0;x<3;x++){
		newPerson(p, y);
		insert_after_LL(list, *p, "Astolfo F");
	}
	
	display_LL(*list);
	printf("\nINSERT LL x3 AFTER NAME: Astolfo F\n");
	system("pause");
	system("CLS");
	
	for(x=0;x<2;x++){
		newPerson(p, y);
		delete_first_LL(list);
		newPerson(p, y);
		delete_last_LL(list);
	}
	display_LL(*list);
	printf("\DELETE LL FIRST LAST x2\n");
	system("pause");
	system("CLS");
	
	delete_by_city_LL(list, "Throne of Heroes H");
	delete_by_city_LL(list, "Throne of Heroes I");
	delete_by_city_LL(list, "Throne of Heroes K");
	
	display_LL(*list);
	printf("\DELETE LL CITIES: H I K\n");
	system("pause");
	system("CLS");
}


