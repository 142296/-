void get_next(int* next, int length, char* s)
{
	next[0] = -1;
	int j = -1;
	for (int i = 1; i < length; i++) {
		while (j >= 0 && s[i] != s[j + 1]) {
			j = next[j];
		}
		if (s[i] == s[j + 1]) {
			j++;
		}
		next[i] = j;
	}
}