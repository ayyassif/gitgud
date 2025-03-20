#ifndef GITGUD_H_
#define GITGUD_H_

#define SUCCESS 1
#define FAILURE 0

int init(void);            // git init
int add(char *path);       // git add
int commit(char *message); // git commit
int push(void);
int pull(void);
int log(void);
int reset(void);

#endif