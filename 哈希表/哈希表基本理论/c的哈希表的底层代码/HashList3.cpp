

~~~
#include "HashList3.h"

int main(int argc, char const *argv[]) {
	HashTable *ht = new HashTable();
	const char *key[] = {"a", "b", "c", "d", "f", "z"};
	const char *value[] = {"value1", "value2", "value3", "value4", "value5", "value6"};
	for (int i = 0; i < 6; ++i) {
		ht->install(key[i], value[i]);
	}
	ht->display();
	return 0;
}
~~~

