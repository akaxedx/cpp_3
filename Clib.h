typedef struct CStashTag{
	int size;
	int quantity;
	int next;
	unsigned char* storage;
}CStash;

void initialize(CStash* s,int size);
void cleanuo(CStash* s);
int add(CStash* s,const void* element);
void* fetch(CStash* s,int index);
int count(CStash* s);
void inflate(CStash* s,int increase);
