#include "shell.h"
#include "comm_sepa.h"

list_cmd *comm_sepa(char *line)
{
	char *token;
	list_cmd *my_list = malloc(sizeof(list_cmd));

	my_list->head = NULL;
	my_list->cur = NULL;
	my_list->tail = NULL;

	token = strtok(line, ";");
	while (token != NULL)
	{
		add_node(my_list, token);
		token = strtok(NULL, ";");
	}
	return (my_list);
}

void add_node(list_cmd *my_list, char *cmd)
{
	node_cmd *new_node = malloc(sizeof(node_cmd));
	new_node->cmd = cmd;
	new_node->next = NULL;
	if (!my_list->head)
	{
		my_list->head = new_node;
		my_list->cur = new_node;
		my_list->tail = my_list->head;
		return;
	}
	my_list->tail->next = new_node;
	my_list->tail = my_list->tail->next;
}

void print_list(list_cmd *my_list)
{
	node_cmd *cur = my_list->head;
	while (cur)
	{
		printf("%s\n", cur->cmd);
		cur = cur->next;
	}
}

void free_list(list_cmd *my_list)
{
	node_cmd *cur = my_list->head;
	node_cmd *next;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
