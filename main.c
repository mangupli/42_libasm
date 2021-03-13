/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspyke <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:13:35 by mspyke            #+#    #+#             */
/*   Updated: 2021/03/13 17:15:08 by mspyke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void clear_buffer(char *buffer, int size)
{
	int i = 0;
	while (i < size)
		buffer[i++] = 0;
}

void	test_ft_strlen()
{
	char	*empty = "";
	char	*hello = "Hello dude";
	char	*alpha = "abcdefghijklmnopqrstuvwxyz";
	char	*your_choice = "Lorem ipsum dolor sit amet, consectetur adipiscing\
elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
tortor, sit amet consequat amet.";
	
	printf("\n================================\n");
	printf("========== FT_STRLEN ===========\n");
	printf("================================\n\n");

	printf("%-20s: \"%s\"\n", "char *", empty);
	printf("%-20s: %zu\n", "libc", strlen(empty));
	printf("%-20s: %zu\n", "libasm", ft_strlen(empty));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", hello);
	printf("%-20s: %zu\n", "libc", strlen(hello));
	printf("%-20s: %zu\n", "libasm", ft_strlen(hello));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", alpha);
	printf("%-20s: %zu\n", "libc", strlen(alpha));
	printf("%-20s: %zu\n", "libasm", ft_strlen(alpha));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", your_choice);
	printf("%-20s: %zu\n", "libc", strlen(your_choice));
	printf("%-20s: %zu\n", "libasm", ft_strlen(your_choice));
	printf("\n");

	/*
	//NULL Segfault
	printf("%-20s: \"%s\"\n", "char *", NULL);
	printf("%-20s: 0\n", "expected lenght");
	printf("%-20s: %zu\n", "libc", strlen(NULL));
	printf("%-20s: %zu\n", "libasm", ft_strlen(NULL));
	printf("\n");
	*/
}

void	test_ft_read()
{	
	int fd = open("main.c", O_RDONLY);
	char buff1[891];
	int ret = 1;
	printf("\n================================\n");
	printf("========== FT_READ =============\n");
	printf("================================\n\n");
	printf("%-20s: \n", "header main.c | libc ");
	ret = read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	close(fd);
	fd = open("main.c", O_RDONLY);
	clear_buffer(buff1, 891);
	printf("%-20s: \n", "header main.c | libasm ");
	ret = ft_read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	clear_buffer(buff1, 891);
	close(fd);
	fd = open("empty_file", O_RDONLY);
	printf("%-20s: \n", "empty_file test | libc ");
	ret = read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	close(fd);
	fd = open("empty_file", O_RDONLY);
	clear_buffer(buff1, 891);
	printf("%-20s: \n", "empty_file test | libasm ");
	ret = ft_read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	clear_buffer(buff1, 891);
	close(fd);

	fd = open("wrong", O_RDONLY);
	printf("%-20s: \n", "wrong | libc ");
	ret = read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	close(fd);
	fd = open("wrong", O_RDONLY);
	clear_buffer(buff1, 891);
	printf("%-20s: \n", "wrong | libasm ");
	ret = ft_read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	clear_buffer(buff1, 891);
	close(fd);
}

void	test_ft_strcmp()
{
	char	*empty = "";
	char	*hello = "to make a difference";
	char	*your_choice = "I am here";
	
	printf("\n================================\n");
	printf("========== FT_STRCMP ===========\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "1 char *", empty);
	printf("%-20s: \"%s\"\n", "2 char *", empty);
	printf("%-20s: %d\n", "libc", strcmp(empty, empty));
	printf("%-20s: %d\n", "libasm", ft_strcmp("", ""));
	printf("\n");
	printf("%-20s: \"%s\"\n", "1 char *", empty);
	printf("%-20s: \"%s\"\n", "2 char *", hello);
	printf("%-20s: %d\n", "libc", strcmp(empty, hello));
	printf("%-20s: %d\n", "libasm", ft_strcmp(empty, hello));
	printf("\n");
	printf("%-20s: \"%s\"\n", "1 char *", hello);
	printf("%-20s: \"%s\"\n", "2 char *", empty);
	printf("%-20s: %d\n", "libc", strcmp(hello, empty));
	printf("%-20s: %d\n", "libasm", ft_strcmp(hello, empty));
	printf("\n");
	printf("%-20s: \"%s\"\n", "1 char *", your_choice);
	printf("%-20s: \"%s\"\n", "2 char *", hello);
	printf("%-20s: %d\n", "libc", strcmp(your_choice, hello));
	printf("%-20s: %d\n", "libasm", ft_strcmp(your_choice, hello));
	printf("\n");
	printf("%-20s: \"%s\"\n", "1 char *", hello);
	printf("%-20s: \"%s\"\n", "2 char *", your_choice);
	printf("%-20s: %d\n", "libc", strcmp(hello, your_choice));
	printf("%-20s: %d\n", "libasm", ft_strcmp(hello, your_choice));
	printf("\n");
	printf("%-20s: \"%s\"\n", "1 char *", your_choice);
	printf("%-20s: \"%s\"\n", "2 char *", your_choice);
	printf("%-20s: %d\n", "libc", strcmp(your_choice, your_choice));
	printf("%-20s: %d\n", "libasm", ft_strcmp(your_choice, your_choice));
	printf("\n");

	/*
	//NULL Segfault
	printf("%-20s: \"%s\"\n", "1 char *", NULL);
	printf("%-20s: \"%s\"\n", "2 char *", your_choice);
	printf("%-20s: %d\n", "libc", strcmp(NULL, your_choice));
	printf("%-20s: %d\n", "libasm", ft_strcmp(NULL, your_choice));
	printf("\n");
	printf("%-20s: \"%s\"\n", "1 char *", your_choice);
	printf("%-20s: \"%s\"\n", "2 char *", NULL);
	printf("%-20s: %d\n", "libc", strcmp(your_choice, NULL));
	printf("%-20s: %d\n", "libasm", ft_strcmp(your_choice, NULL));
	printf("\n");
	printf("%-20s: \"%s\"\n", "1 char *", NULL);
	printf("%-20s: \"%s\"\n", "2 char *", NULL);
	printf("%-20s: %d\n", "libc", strcmp(NULL, NULL));
	printf("%-20s: %d\n", "libasm", ft_strcmp(NULL, NULL));
	printf("\n");
	*/
}

void	test_ft_write()
{
	char *hello = "Hey dude\n";
	char *empty = "";

	printf("\n================================\n");
	printf("========== FT_WRITE ===========\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char *", hello);
	printf("%-20s: \"Libc  : %zu\"\n", "libc", write(1, hello, ft_strlen(hello)));
	printf("%-20s: \"Libasm: %zu\"\n", "libasm", ft_write(1, hello, ft_strlen(hello)));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", empty);
	printf("%-20s: \"Libc  : %zu\"\n", "libc", write(1, empty, ft_strlen(empty)));
	printf("%-20s: \"Libasm: %zu\"\n", "libasm", ft_write(1, empty, 0));
	printf("\nCheck for spoiled file descriptor\n");
	printf("%-20s: \"Libc  : %zu\"\n", "libc", write(6, empty, ft_strlen(empty)));
	printf("%-20s: \"Libasm: %zu\"\n", "libasm", ft_write(6, empty, 0));
	printf("\n");
}


void	test_ft_strcpy()
{
	
	char buffer[1000];
	char *empty = "";
	char *hello_world = "Hello dude";
	char	*long_str = "Lorem ipsum dolor sit amet, consectetur adipiscing\
elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
tortor, sit amet consequat amet.";
	
	printf("\n================================\n");
	printf("========== FT_STRCPY ===========\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char []", empty);
	printf("%-20s: buffer[1000]\n", "copy to");
	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer, empty));	
	clear_buffer(buffer, 1000);
	printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(buffer, empty));	
	clear_buffer(buffer, 1000);
	printf("\n");
	printf("%-20s: \"%s\"\n", "char []", hello_world);
	printf("%-20s: buffer[1000]\n", "copy to");
	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer, hello_world));	
	clear_buffer(buffer, 1000);
	printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(buffer, hello_world));	
	clear_buffer(buffer, 1000);
	printf("\n");
	printf("%-20s: \"%s\"\n", "char []", long_str);
	printf("%-20s: buffer[1000]\n", "copy to");
	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer, long_str));	
	clear_buffer(buffer, 1000);
	printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(buffer, long_str));
	clear_buffer(buffer, 1000);
	printf("\n");

	/*
	//NULL Segfault
	printf("%-20s: \"%s\"\n", "char []", NULL);
	printf("%-20s: buffer[1000]\n", "copy to");
	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer,NULL));
	clear_buffer(buffer, 1000);
	printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(buffer, NULL));
	clear_buffer(buffer, 1000);
	printf("\n");	
	printf("%-20s: \"%s\"\n", "char []", hello_world);
	printf("%-20s: %s\n", "copy to", NULL);
	printf("%-20s: \"%s\"\n", "libc", strcpy(NULL, hello_world));
	printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(NULL, hello_world));
	printf("\n");
	*/
}

void	test_ft_strdup()
{
	char	*save1;
	char	*save2;
	char	*long_str = "Lorem ipsum dolor sit amet, consectetur adipiscing\
elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
tortor, sit amet consequat amet.";
	char	*empty = "";
	char	*hello = "Hello dude";
	
	printf("\n================================\n");
	printf("========== FT_STRDUP ===========\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char *", empty);
	save1 = strdup(empty);
	printf("%-20s: \"%s\"\n", "libc", save1);
	free(save1);
	save1 = NULL;
	save2 = ft_strdup(empty);
	printf("%-20s: \"%s\"\n", "libasm", save2);
	free(save2);
	save2 = NULL;
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", hello);
	save1 = strdup(hello);
	printf("%-20s: \"%s\"\n", "libc", save1);
	free(save1);
	save1 = NULL;
	save2 = ft_strdup(hello);
	printf("%-20s: \"%s\"\n", "libasm", save2);
	free(save2);
	save2 = NULL;
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", long_str);
	save1 = strdup(long_str);
	printf("%-20s: \"%s\"\n", "libc", save1);
	free(save1);
	save1 = NULL;
	save2 = ft_strdup(long_str);
	printf("%-20s: \"%s\"\n", "libasm", save2);
	free(save2);

	/*
	//NULL Segfault
	save2 = NULL;
	printf("\n");
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", NULL);
	save1 = strdup(NULL);
	save2 = ft_strdup(NULL);
	printf("%-20s: \"%s\"\n", "libasm", save2);
	free(save2);
	save2 = NULL;
	*/
}

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		test_ft_strlen();
		test_ft_read();
		test_ft_strcmp();
		test_ft_write();
		test_ft_strcpy();
		test_ft_strdup();
	}
	else if (argc == 2 && !strcmp(argv[1], "ft_strlen"))
		test_ft_strlen();
	else if (argc == 2 && !strcmp(argv[1], "ft_read"))
		test_ft_read();
	else if (argc == 2 && !strcmp(argv[1], "ft_strcmp"))
		test_ft_strcmp();
	else if (argc == 2 && !strcmp(argv[1], "ft_write"))
		test_ft_write();
	else if (argc == 2 && !strcmp(argv[1], "ft_strcpy"))
		test_ft_strcpy();
	else if (argc == 2 && !strcmp(argv[1], "ft_strdup"))
		test_ft_strdup();
	return (0);
}
