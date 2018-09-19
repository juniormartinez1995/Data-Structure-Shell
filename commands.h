
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
int ts_remove(char **args);
int ts_insere_varios(char **args);

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
  "ts-busca",
  "ts-remove",
  "ts-insere-varios"
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
  &ts_busca,
  &ts_remove,
  &ts_insere_varios
};

