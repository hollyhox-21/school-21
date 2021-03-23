/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:43:04 by rjoella           #+#    #+#             */
/*   Updated: 2021/03/22 19:42:31 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	test_write(char *filename)
{
	int		ft_fd;
	int		or_fd;
	int		ft;
	int		or;
	int		ft_errno;
	int		or_errno;
	char	*buf;

	buf = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris tristique dui at tellus blandit vulputate.";
	or_fd = open(filename, O_RDWR);
	or = write(or_fd, buf, 63);
	or_errno = errno;
	if (or_fd > 0)
		close(or_fd);
	ft_fd = open(filename, O_RDWR);
	ft = ft_write(ft_fd, buf, 63);
	ft_errno = errno;
	if (ft_fd > 0)
		close(ft_fd);
	(or == ft) ? OK : KO;
	if (ft == -1 || or == -1)
		(ft_errno == or_errno) ? OK : KO;
}

static void	test_read(char *filename)
{
	int		or_fd;
	int		ft_fd;
	int		or;
	int		ft;
	int		or_errno;
	int		ft_errno;
	char	or_buf[256];
	char	ft_buf[256];

	bzero(ft_buf, 256);
	bzero(or_buf, 256);
	or_fd = open(filename, O_RDONLY);
	or = read(or_fd, or_buf, 255);
	or_errno = errno;
	if (or_fd > 0)
		close(or_fd);
	ft_fd = open(filename, O_RDONLY);
	ft = ft_read(ft_fd, ft_buf, 255);
	ft_errno = errno;
	if (ft_fd > 0)
		close(ft_fd);
	(or == ft && !strcmp(or_buf, ft_buf)) ? OK : KO;
	if (ft == -1 || or == -1)
		(ft_errno == or_errno) ? OK : KO;
}

void	test_strlen(char *str)
{
	int	my_i;
	int	orig_i;

	my_i = ft_strlen(str);
	orig_i = strlen(str);
	(my_i == orig_i) ? OK : KO;
}

void	test_strcpy(char *src)
{
	char	dest1[200];
	char	dest2[200];

	bzero(dest1, 200);
	bzero(dest2, 200);
	ft_strcpy(dest1, src);
	strcpy(dest2, src);
	(!strcmp(dest1, dest2)) ? OK : KO;
}

void	test_strcmp(char *s1, char *s2)
{
	int	my;
	int	orig;

	my = ft_strcmp(s1, s2);
	orig = strcmp(s1, s2);
	(my == orig) ? OK : KO;
}

void	test_strdup(char *str)
{
	char	*my;
	char	*orig;
	
	my = ft_strdup(str);
	orig = strdup(str);
	
	!(strcmp(my, orig)) ? OK : KO;
}

int main(void)
{
	int	fd;
	printf("FT_STRLEN--->\t");
	test_strlen("asdf");
	test_strlen("Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
	test_strlen("");
	test_strlen("\n");
	test_strlen("\n\n");
	test_strlen("111+}Te'st!wi/th*[<<As:c2ii3");
	printf("\n");
	printf("FT_STRCPY--->\t");
	test_strcpy("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris tristique dui at tellus blandit vulputate.");
	test_strcpy("");
	test_strcpy("\n");
	test_strcpy("111+}Te'st!wi/th*[<<As:c2ii3");
	test_strcpy("FIZZ\0BUZZ");
	test_strcpy("\x12\xff");
	printf("\n");
	printf("FT_STRCMP--->\t");
	test_strcmp("Hello world", "Hello world");
	test_strcmp("Hello world", "");
	test_strcmp("\200", "\0");
	test_strcmp("111+}Te'st!wi/th*[<<As:c2ii3", "111+}Te'st!wi/th*[<<As:c2ii");
	test_strcmp("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris tristique dui at tellus blandit vulputate.", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris tristique dui at tellus blandit vulputate.");
	test_strcmp("FIZZ\0BUZZ", "FIZZ\0");
	printf("\n");
	printf("FT_STRDUP--->\t");
	test_strdup("FIZZ\0BUZZ");
	test_strdup("Hello world");
	test_strdup("");
	test_strdup("\x12\xff");
	test_strdup("\n\n");
	test_strdup("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris tristique dui at tellus blandit vulputate.");
	printf("\n");
	printf("FT_READ  --->\t");
	test_read("test1.txt");
	test_read("test2.txt");
	test_read("not_valid");
	fd = open("test3.txt", O_CREAT, 0000);
	close(fd);
	test_read("test3.txt");
	printf("\n");
	printf("FT_WRITE --->\t");
	test_write("test1.txt");
	test_write("test2.txt");
	test_write("test3.txt");
	test_write("not_valid");
	printf("\n");
	return (0);
}