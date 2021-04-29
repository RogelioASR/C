#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include"help.h"

main() {
	
	node* n = NULL;
	node* tree = NULL; 
	
	int i = 0, j = 0, count = 0;
	char c, name[100], password[100], line[200], type[100];
	
	while(1) {
		i = 0, j = 0;
		while((c = getchar()) != EOF && c != '\n') {
			line[i++] = c;
			if(isspace(c))
				count++;
		}	
		line[i] = '\0';
	
		if(count >= 2) {
			i = getdata(type, line);
			i += getdata(name, line+i);
			i += getdata(password, line+i);
		}

		if(strstr(type, "add") && name && password) {
			n = insert(name, password, tree);
			if (tree == NULL)
				tree = n;
			show(tree);
		}
		else if (strstr(type, "remove"))
			printf("User removed");
		else
			printf("Invalid user, try again\n\n");
	}
}

void show(node* position) {
	
	if (position != NULL) {
    	printf("%s,  ", position->name);
    if(position->left != NULL)
    	printf("%s,  ", position->left);
    if(position->right != NULL)
    	printf("%s,  ", position->right);
	}
	printf("\n");
	return;
}

node *insert(char *name, char *password, node* pos) {
	
	node* temp;
	if (pos == NULL) {
		pos = (node*)malloc(sizeof(node));
    	pos->name = name;
    	pos->password = password;
	} else if(pos->right == NULL) {
		pos->right = (node*)malloc(sizeof(node));
    	pos->name = name;
    	pos->password = password;
	} else if(pos->left == NULL) {
		pos->left = (node*)malloc(sizeof(node));
    	pos->name = name;
    	pos->password = password;
}
	/*
	else {	
		if (pos->name == name) {
    		printf("User already redistered\n");
    		return;
    } else if (pos->name > name) { 
			pos = insert(name, password, pos->left);
    		if (pos->left == NULL) {
				pos->left = temp;
    	} 
	}	else {
    	pos = insert(name, password, pos->right);
    	if (pos->right == NULL) {
			pos->right = temp;
	}
    }
}*/
    printf("User succesfully added\n\n");
	return pos;
}

int getdata(char *user, char *line) {

	int i = 0, j = 0;
	if(isspace(line[0]))
		while(isspace(line[++i]));
	while(!isspace(line[i]))
		user[j++] = line[i++];
	user[i] = '\0';
		return i;
}

