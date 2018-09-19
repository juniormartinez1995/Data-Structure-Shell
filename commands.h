
/*
  Function Declarations for builtin shell commands:
 */
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);
int lsh_sobre(char **args);

int ts_init(char **args);
int ts_print(char **args);
int ts_destroy(char **args);
int ts_insere(char **args);
int ts_busca(char **args);

/*
  List of builtin commands, followed by their corresponding functions.
 */
char *builtin_str[] = {
  "cd",
  "help",
  "exit",
  "creditos",
  "ts-init",
  "ts-print",
  "ts-destroy",
  "ts-insere",
  "ts-busca"
};

int (*builtin_func[]) (char **) = {
  &lsh_cd,
  &lsh_help,
  &lsh_exit,
  &lsh_sobre,
  &ts_init,
  &ts_print,
  &ts_destroy,
  &ts_insere,
  &ts_busca
};

