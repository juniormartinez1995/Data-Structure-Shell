#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"

#define LSH_RL_BUFSIZE 1024

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"


/* COMANDOS ===============================*/

/*
  List of builtin commands, followed by their corresponding functions.
 */

//
int lsh_num_builtins(void) {
  return sizeof(builtin_str) / sizeof(char *);
}

/*
  Builtin function implementations.
*/
/*
int lsh_cd(char **args)
{ 
  if (args[1] == NULL) {
    fprintf(stderr, "ED: argumento esperado como \"cd\"\n");
  } else {
    if (chdir(args[1]) != 0) {
      perror("lsh");
    }
  }
 
  return 1;
}
*/

int lsh_help(char **args)
{
  int i;
  printf("Processando %s ...\n",args[0]);
  printf("Entre comandos e argumentos, e tecle ENTER.\n");
  printf("Os seguintes comandos estao disponiveis:\n");

  for (i = 0; i < lsh_num_builtins(); i++) {
    printf("  %s\n", builtin_str[i]);
  }

  printf("Consulte o material da disciplina para outras informacoes.\n");
  return 1;
}


int lsh_exit(char **args)
{
  printf("Processando %s ...\n",args[0]);
  return 0;
}

int lsh_sobre(char **args)
{
  printf("Processando %s ...\n",args[0]);
  printf("Disciplina Algoritmos e Estrutura de Dados II\n");
  printf("Prof. Manoel Mendonca\n");
  printf("Shell baseada na LSH de Stephen Brennan\n");
  return 1;
}



/* CONSOLE =================================*/

/* 
  le uma linha do console
*/

char *lsh_read_line(void)
{
  int bufsize = LSH_RL_BUFSIZE;
  int position = 0;
  char *buffer = malloc(sizeof(char) * bufsize);
  int c;

  if (!buffer) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  while (1) {
    // Read a character
    c = getchar();

    // If we hit EOF, replace it with a null character and return.
    if (c == EOF || c == '\n') {
      buffer[position] = '\0';
      return buffer;
    } else {
      buffer[position] = c;
    }
    position++;

    // If we have exceeded the buffer, reallocate.
    if (position >= bufsize) {
      bufsize += LSH_RL_BUFSIZE;
      buffer = realloc(buffer, bufsize);
      if (!buffer) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}



/*
   Faz o Parser da linha lida
*/
char **lsh_split_line(char *line)
{
  int bufsize = LSH_TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  if (!tokens) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, LSH_TOK_DELIM);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += LSH_TOK_BUFSIZE;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, LSH_TOK_DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}


int lsh_execute(char **args)
{
  int i;

  if (args[0] == NULL) {
    // An empty command was entered.
    return 1;
  }

  for (i = 0; i < lsh_num_builtins(); i++) {
    if (strcmp(args[0], builtin_str[i]) == 0) {
      return (*builtin_func[i])(args);
    }
  }
   
   printf("Comando indefinido: \" %s\"\n", args[0]);
  
  // Vers?o concorrrente
  // return lsh_launch(args);
  return 1;
}



void lsh_loop()
{
  char *line;
  char **args;
  int status;

  printf("Entre um comando ou tecle help para obter ajuda\n");
  do {
    printf("NOSSA ED> ");
    line = lsh_read_line();
    args = lsh_split_line(line);
    status = lsh_execute(args);

    free(line);
    free(args);
  } while (status);
}


//int main(int argc, char *argv[])
int main()
{
  // Load config files, if any.

  // Run command loop.
  lsh_loop();

  // Perform any shutdown/cleanup.

  return EXIT_SUCCESS; 
}

