/*
  Function Declarations for builtin shell commands:
 */
// int lsh_cd(char **args);
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
int fi_init(char **args);
int fi_enfile(char **args);
int fi_desenfile(char **args);
int fi_print(char **args);
int arv_init(char **args);
int arv_insere(char **args);
int arv_insere_varios(char **args);
int arv_print_em_ordem(char **args);
int arv_print_pre_ordem(char **args);
int arv_print_pos_ordem(char **args);
int arv_altura(char **args);
int arv_num_nos(char **args);
int arv_busca(char **args);
int arv_remove(char **args);

/*
  List of builtin commands, followed by their corresponding functions.
 */
char *builtin_str[] = {
//  "cd",
  "help",
  "exit",
  "creditos",
  "ts-init", 			// Tabela Sequencial
  "ts-print",
  "ts-destroi",
  "ts-insere",
  "ts-busca",
  "ts-remove",
  "ts-insere-varios",
  "fi-init", 			// Fila
  "fi-enfile",
  "fi-desenfile",
  "fi-print",
  "arv-init",
  "arv-insere",			// Arvore Binaria
  "arv-insere-varios",
  "arv-print-emOrd",
  "arv-print-preOrd",
  "arv-print-posOrd",
  "arv-altura",
  "arv-num-nos",
  "arv-busca",
  "arv-remove"
};

int (*builtin_func[]) (char **) = {
//  &lsh_cd,
  &lsh_help,
  &lsh_exit,
  &lsh_sobre,
  &ts_init,
  &ts_print,
  &ts_destroy,
  &ts_insere,
  &ts_busca,
  &ts_remove,
  &ts_insere_varios,
  &fi_init,
  &fi_enfile,
  &fi_desenfile,
  &fi_print,
  &arv_init,
  &arv_insere,
  &arv_insere_varios,
  &arv_print_em_ordem,
  &arv_print_pre_ordem,
  &arv_print_pos_ordem,
  &arv_altura,
  &arv_num_nos,
  &arv_busca,
  &arv_remove
};

