/*
Showing the hexadecimal representation of the data using show_bytes function presented in
"Computer Systems" by Randal E. Bryant & David R. O'Hallaron
*/
#include <stdio.h>

void show_bytes(unsigned char *ptr_data, unsigned int size)
{
	unsigned int i;

	for(i=0; i<size; i++)
		printf("%.2x ", *(ptr_data+i));
    printf("\n");
}


void show_int(int i)
{
	show_bytes((char *) &i, sizeof(i));
}

void show_float(float f)
{
	show_bytes((char *) &f, sizeof(f));
}

void show_double(double d)
{
	show_bytes((char *) &d, sizeof(d));
}


struct node_only_num {
    int i;
};

struct node {
    int i;
    struct node *next;
};

struct node_i_f_next {
    int i;
    float f;
    struct node_i_f_next *next;
};

struct node_i_next_f {
    int i;
    struct node_i_next_f *next;
    float f;
};

int main()
{
    int i = 1;
	float f = 1;
	double d;

    printf("\n------------ Print hex value of int number %d ------------\n", i);
    printf("Using show_bytes: \t");
	show_int(i);
    printf("Using casting: \t\t");
	printf("%.8x\n", i);

    printf("\n\n------------ Print hex value of structure having only an integer equal to %d ------------\n", i);
    struct node_only_num nd;
    nd.i = i;
    printf("Using show_bytes: \t");
	show_bytes((unsigned char *)&nd, sizeof(nd));

    printf("\n\n------------ Print hex value of structure having int equal to %d and a \"next\" uninitialized ------------\n", i);
    struct node nd1;
    nd1.i = i;
    printf("Using show_bytes: \t");
	show_bytes((unsigned char *)&nd1, sizeof(nd1));
    printf("\n------------ Note that in above representation the data structure is 16 bytes while integer is 4 bytes");
    printf("\n             and the pointer is 8 bytes, the other 4 bytes are for data alignment             ------------\n");

    printf("\n\n------------ Print hex value of structure having int to equal %d and a \"next\" initialized with NULL ------------\n", i);
    struct node nd2;
    nd2.i = i;
    nd2.next = NULL;
    printf("Using show_bytes: \t");
	show_bytes((unsigned char *)&nd2, sizeof(nd2));
    printf("\n------------ Note that in above representation the data structure is 16 bytes while integer is 4 bytes");
    printf("\n             and the pointer is 8 bytes, the other 4 bytes are for data alignment             ------------\n");
    
    
    printf("\n\n------------ Print hex value of structure having int equal to %d and a \"next\" initialized with 0xabcd ------------\n", i);
    nd2.i = i;
    nd2.next = (struct node *)0xabcd;
    show_bytes((unsigned char *)&nd2, sizeof(nd2));
    printf("\n------------ Note that in above representation the data structure is 16 bytes while integer is 4 bytes");
    printf("\n             and the pointer is 8 bytes, the other 4 bytes are for data alignment             ------------\n");

    printf("\n\n------------ Print hex value of structure having int equal to %d and f equal to %f and a \"next\" initialized with 0xabcdef12abcdef34 ------------\n", i, f);
    struct node_i_f_next nd3;
    nd3.i = i;
    nd3.f = f;
    nd3.next = (struct node_i_f_next *)0xabcdef12abcdef34;;
    printf("Using show_bytes: \t");
	show_bytes((unsigned char *)&nd3, sizeof(nd3));

    printf("\n------------ Print hex value of structure having int equal to %d, and \"next\" initialized with 0xabcdef12abcdef34, and f equal to %f ------------\n", i, f);
    /*Note that the first element of the structure is "int", the second structure pointer of "next", and the last is "float"*/
    struct node_i_next_f nd4;
    nd4.i = i;
    nd4.f = f;
    nd4.next = (struct node_i_next_f *) 0xabcdef12abcdef34;
    printf("Using show_bytes (structure of nd4): \t");
	show_bytes((unsigned char *)&nd4, sizeof(nd4));
    printf("\n------------ Note that in above representation the data structure is 24 bytes while integer is 4 bytes");
    printf("\n             the pointer is 8 bytes, and the float is 4 bytes; the other 8 bytes are for data alignment");  
    printf("\n             because pointer is put between int and float each of int and float variables need 8 bytes (for alignment)      ------------\n");     
    
	struct node_i_next_f *ptr_nd4 = &nd4;
	printf("Using show_bytes (address of structure of nd4): \t");
	show_bytes((unsigned char *)&ptr_nd4, sizeof(ptr_nd4));

 	struct node_i_next_f nd5;
    nd5.i = -i;
    nd5.f = -f;
    nd5.next = &nd4;

    printf("Using show_bytes (structure of nd5): \t");
	show_bytes((unsigned char *)&nd5, sizeof(nd5)); 


	printf("\n------------ Print hex value of float number %f ------------\n", f);
    printf("Using show_bytes: \t");
	show_float(f);
    printf("Using casting: \t\t");
	printf("%x\n", *(int *)&f);

    printf("\n------------ Print hex value of double number %f ------------\n", f);
    printf("Using show_bytes: \t");
	show_double((double)f);
    printf("Using casting: \t\t");
    d = f;
	printf("%llx\n", *((long long int *)&d));

    return(0);
}
