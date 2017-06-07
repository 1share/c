#include<stdio.h>
#include<string.h>

void myfile_write() {
	FILE *file = fopen("/tmp/c.log", "a+");

	if (!file) return;

  	fwrite("hello world\n",1,strlen("hello world\n"),file);	
	fclose(file);
}


void myfile_read() {
	FILE *file = fopen("/tmp/c.log", "r");

	if (!file) return;

	char buf[1024] = {};

	int n;

	while (!feof(file)){
		if ((n = fread(buf, 1, 36, file))==0) break;

		printf("%d\n", n);
		printf("%s", buf);
		buf[0] = '\0';
	}

	buf[0] = '\0';
	fseek(file,0L,SEEK_SET);
	while (fgets(buf, 1024, file)!=NULL){
		printf("new:%s", buf);
		buf[0] = '\0';
	}

	buf[0] = '\0';
	fseek(file,0L,SEEK_SET);
	while(!feof(file)) {
		if (fgets(buf, 1024, file) == NULL) break;
		
		printf("new:%s", buf);
                buf[0] = '\0';
	}

	fclose(file);
}


int main(int argc, char *argv[]) {

	myfile_write();

	myfile_read();
	return 0;
}

