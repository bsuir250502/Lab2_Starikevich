#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "mylib.h"

#define maxlength 15
#define minlength 3
#define exams_num exams_number[(students[i].term)-1]

    int exams_number[4] = { 3, 5, 4, 5 };

    typedef struct {
	char name[maxlength];
	char surname[maxlength];
	char middlename[maxlength];
    } name_T;

    typedef union {
	int term1[3];
	int term2[5];
	int term3[4];
	int term4[5];
    } sessions_T;

    typedef struct {
	name_T names;
	sessions_T sessions;
	int term;
    } student_T;

    int input_names(student_T *, int);
    char myget_arg(int, char **);
    int *choose_term_array(student_T *, int);
    int input_results(student_T *, int);
    int print_results(student_T *, int);
    char *subject_list(int exam);

    int main(int argc, char **argv) {
	printf("\n");
	student_T *students;
	int i, students_num, term;
	char argument;
	argument = myget_arg(argc, argv);
	switch (argument) {
	case 'h':
	    {
		print_manual();
		return 0;
	    }
	case '0':
	    {
		printf
		    ("Error! Please, enter the correct argument:\n[-t1, -t2, -t3, -t4], if you want to set one of 4 terms\n[-h], to display README file...\n\n");
		return 0;
	    }
	default:
	    {
		term = atoi(&argument);
	    }
	}

	printf("[Input]\n");
	printf("Please, enter the number of students: ");
	students_num = myget_int();
	students = (student_T *) malloc(students_num * sizeof(student_T));
	if (!students)
	    return 1;
	input_names(students, students_num);
	for (i = 0; i < students_num; i++)
	    students[i].term = term;
	input_results(students, students_num);
	printf("\n[Output]");
	print_results(students, students_num);
	free(students);
	printf("\n\n");

	return 0;
    }

    char myget_arg(int argc, char **argv) {
	if (argc == 2) {
	    if (!(strcmp(argv[1], "-t1")))
		return '1';
	    if (!(strcmp(argv[1], "-t2")))
		return '2';
	    if (!(strcmp(argv[1], "-t3")))
		return '3';
	    if (!(strcmp(argv[1], "-t4")))
		return '4';
	    if (!(strcmp(argv[1], "-h")))
		return 'h';
	}

	return '0';
    }

    int input_names(student_T * students, int students_num) {
	int i;
	for (i = 0; i < students_num; i++) {
	    printf("\n(Student #%d):", i + 1);

	    printf("\nThe name: ");
	    __fpurge(stdin);
	    myget_str(students[i].names.name, maxlength);

	    printf("The surname: ");
	    __fpurge(stdin);
	    myget_str(students[i].names.surname, maxlength);

	    printf("The middlename: ");
	    __fpurge(stdin);
	    myget_str(students[i].names.middlename, maxlength);
	}

	return 0;
    }

    int *choose_term_array(student_T * students, int i) {
	int *term;
	switch (students[i].term) {
	case 1:
	    term = students[i].sessions.term1;
	    break;

	case 2:
	    term = students[i].sessions.term2;
	    break;

	case 3:
	    term = students[i].sessions.term3;
	    break;

	case 4:
	    term = students[i].sessions.term4;
	    break;
	}

	return term;
    }

    int input_results(student_T * students, int students_num) {
	int i, exam, *term;
	for (i = 0; i < students_num; i++) {
	    printf("\n(Student: #%d, %s %s %s):\n", i + 1,
		   students[i].names.name, students[i].names.surname,
		   students[i].names.middlename);
	    term = choose_term_array(students, i);
	    for (exam = 0; exam < exams_num; exam++) {
		printf("Enter the result of subject '%s' [1-10]: ",
		       subject_list(exam));
		term[exam] = myget_int_range(1, 10);
	    }
	}

	return 0;
    }

    int print_results(student_T * students, int students_num) {
	int i, exam, *term;
	for (i = 0; i < students_num; i++) {
	    printf("\n(Student: #%d, %s %s %s):\n", i + 1,
		   students[i].names.name, students[i].names.surname,
		   students[i].names.middlename);
	    term = choose_term_array(students, i);
	    for (exam = 0; exam < exams_num; exam++) {
		printf("Subject: %s - Result: %d\n", subject_list(exam),
		       term[exam]);
	    }
	}
	return 0;
    }

    char *subject_list(int exam) {
	char *list[] =
	    { "Math", "Physics", "Programming", "Engineering", "English" };

	return list[exam];
    }

#ifdef __cplusplus
}
#endif
