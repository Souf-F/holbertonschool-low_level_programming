#ifndef DOG_H
#define DOG_H
/**
 * struct dog - A dog's basic info
 * @name: First member (Pointer to char)
 * @age: Second member (Float)
 * @owner: Third member (Pointer to char)
 *
 * Description: This structure stores the identity and age of a dog,
 * along with the name of its owner.
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};
typedef struct dog dog_t;
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif
