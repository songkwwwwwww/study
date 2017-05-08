
char* trim(char* phrase) {
	char* old = phrase;
	char* new = phrase;

	while (*old == ' ') {
		old++;
	}
	while (*old) {
		*(new++) = *(old++);
	}
	*new = 0;
	return (char*)realloc(phrase, strlen(phrase) + 1);
}
