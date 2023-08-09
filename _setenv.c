
#include "shell.h"

typedef struct EnvVarNode {
    char *name;
    char *value;
    struct EnvVarNode *next;
} EnvVarNode;

static EnvVarNode *env_head = NULL;

/**
 * _setenv - set the value of an environment variable
 * @name: name of the environment variable
 * @value: value to be set
 * @overwrite: flag to indicate whether to overwrite if the variable already exists
 * Return: 0 on success, -1 on failure
 */
// int _setenv(char *name, char *value, int overwrite)
int _setenv(const char *name, const char *value, int overwrite)
{
    if (name == NULL)
        return -1;

    // Check if the variable already exists
    for (EnvVarNode *node = env_head; node != NULL; node = node->next) {
        if (_strcmp(node->name, name) == 0) {
            if (!overwrite)
                return 0;

            // Update the existing variable's value
            free(node->value);
            node->value = strdup(value);
            if (node->value == NULL)
                return -1;
            return 0;
        }
    }

    // Create a new entry for the variable
    EnvVarNode *new_node = malloc(sizeof(EnvVarNode));
    if (new_node == NULL)
        return -1;

    new_node->name = strdup(name);
    new_node->value = strdup(value);
    if (new_node->name == NULL || new_node->value == NULL) {
        free(new_node->name);
        free(new_node->value);
        free(new_node);
        return -1;
    }

    // Add the new entry to the linked list
    new_node->next = env_head;
    env_head = new_node;

    return 0;
}











// #include "shell.h"
// /**
//  * _setenv - set the value of an environment variable
//  * @name: name of the environment variable
//  * @value: value to be set
//  * @overwrite: flag to indicate whether to overwrite if the variable already exists
//  * Return: 0 on success, -1 on failure
//  */
// int _setenv(const char *name, const char *value, int overwrite)
// {
// 	char *env_val, *new_env_entry;
// 	int i, len;

// 	if (name == NULL)
// 		return (-1);

// 	len = strlen(name);

// 	for (i = 0; environ[i] != NULL; i++)
// 	{
// 		env_val = environ[i];
// 		if (strncmp(name, env_val, len) == 0 && env_val[len] == '=')
// 		{
// 			if (!overwrite)
// 				return (0);

// 			new_env_entry = malloc(len + strlen(value) + 2);
// 			if (new_env_entry == NULL)
// 				return (-1);

// 			sprintf(new_env_entry, "%s=%s", name, value);
// 			environ[i] = new_env_entry;
// 			return (0);
// 		}
// 	}

// 	// If the environment variable doesn't exist, create a new entry
// 	new_env_entry = malloc(len + strlen(value) + 2);
// 	if (new_env_entry == NULL)
// 		return (-1);

// 	sprintf(new_env_entry, "%s=%s", name, value);
// 	environ[i] = new_env_entry;
// 	environ[i + 1] = NULL;
// 	return (0);
// }

