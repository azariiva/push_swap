/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:09:17 by blinnea           #+#    #+#             */
/*   Updated: 2020/03/11 18:35:25 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef EOF
#  define EOF -1
# endif

/*
** ************************************************************************** **
**							MEMORY FUNCTIONS								  **
** ************************************************************************** **
*/
/*
** The ft_memset() function writes len bytes of value c (converted to an
** unsigned char) to the string b
*/
void			*ft_memset(void *b, int c, size_t len);
/*
** Allocates (with malloc()) and returns a “fresh” memory area. The memory
** allocated is initialized to 0. If the allocation fails, the function returns
** NULL.
*/
void			*ft_memalloc(size_t size);
/*
** Takes as a parameter the address of a memory area that needs to be freed with
** free(), then puts the pointer to NULL.
*/
void			ft_memdel(void **ap);
/*
** The ft_memcpy() function copies n bytes from memory area src to memory area
** dst. If dst and src overlap, behavior is undefined.  Applications in which
** dst and src might overlap should use ft_memmove() instead.
*/
void			*ft_memcpy(void *dst, const void *src, size_t n);
/*
** The ft_memccpy() function copies bytes from string src to string dst.  If the
** character c (as converted to an unsigned char) occurs in the string src, the
** copy stops and a pointer to the byte after the copy of c in the string dst is
** returned.  Otherwise, n bytes are copied, and a NULL pointer is returned.
**
** The source and destination strings should not overlap, as the behavior is
** undefined.
*/
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
/*
** The ft_memmove() function copies len bytes from string src to string dst. The
** two strings may overlap; the copy is always done in a non-destructive manner.
*/
void			*ft_memmove(void *dst, const void *src, size_t len);
/*
** The ft_memchr() function locates the first occurrence of c (converted to an
** unsigned char) in string s.
*/
void			*ft_memchr(const void *s, int c, size_t n);
/*
** The ft_memcmp() function compares byte string s1 against byte string s2. Both
** strings are assumed to be n bytes long.
*/
int				ft_memcmp(const void *s1, const void *s2, size_t n);
/*
** The ft_bzero() function writes n zeroed bytes to the string s.  If n is zero,
** ft_bzero() does nothing.
*/
void			ft_bzero(void *s, size_t n);

/*
** ************************************************************************** **
**							INTEGER FUNCTIONS								  **
** ************************************************************************** **
*/
/*
** The ft_abs() function computes the absolute value of the integer i.
*/
int				ft_abs(int i);
/*
** The ft_labs() function returns the absolute value of the long integer i.
*/
long			ft_labs(long i);
/*
** The ft_llabs() function returns the absolute value of i.
*/
long long		ft_llabs(long long i);

/*
** ************************************************************************** **
**						STRING FUNCTIONS									  **
** ************************************************************************** **
*/
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle, \
		size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_itoa(int n);
int				ft_atoi(const char *str);

/*
** ctype functions
*/
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isblank(int c);
int				ft_iscntrl(int c);
int				ft_isdigit(int c);
int				ft_isgraph(int c);
int				ft_islower(int c);
int				ft_isprint(int c);
int				ft_ispunct(int c);
int				ft_isspace(int c);
int				ft_isupper(int c);
int				ft_isxdigit(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

/*
** ************************************************************************** **
**						PRINT FUNCTIONS										  **
** ************************************************************************** **
*/
/*
** The ft_putchar_fd() function writes the character c (converted to an
** ``unsigned char'') to the file descriptor fd.
*/
int				ft_putchar_fd(char c, int fd);
/*
** The ft_putchar() function is identical to ft_putchar_fd() with a file
** descriptor STDOUT_FILENO.
*/
int				ft_putchar(char c);
/*
** Outputs the string str to the file descriptor fd.
*/
int				ft_putstr_fd(char const *str, int fd);
/*
** The ft_putstr() function is identical to ft_putsrt_fd() with a file
** descriptor STDOUT_FILENO
*/
int				ft_putstr(char const *str);
/*
** Outputs the string str followed by a '\n' to the file descriptor fd.
*/
int				ft_putendl_fd(char const *str, int fd);
/*
** The ft_putendl() function is identical to ft_putendl_fd() with a file
** descriptor STDOUT_FILENO
*/
int				ft_putendl(char const *s);
/*
** Outputs the integer n to the file descriptor fd.
*/
int				ft_putnbr_fd(int n, int fd);
/*
** The ft_putnbr() function is identical to ft_putnbr_fd() with a file
** descriptor STDOUT_FILENO
*/
int				ft_putnbr(int n);

/*
** ************************************************************************** **
**						LIST FUNCTIONS										  **
** ************************************************************************** **
*/
typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;
/*
** Allocates (with malloc(3)) and returns a “fresh” link. The variables content
** and content_size of the new link are initialized by copy of the parameters of
** the function. If the parameter content is nul, the variable content is
** initialized to NULL and the variable content_size is initialized to 0 even if
** the parameter content_size isn’t. The variable next is initialized to NULL.
** If the allocation fails, the function returns NULL.
*/
t_list			*ft_lstnew(void const *content, size_t content_size);
/*
** Takes as a parameter a link’s pointer address and frees the memory of the
** link’s content using the function del given as a parameter, then frees the
** link’s memory using free(3). Finally, the pointer to the link that was just
** freed sets to NULL.
*/
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
/*
** Takes as a parameter a link’s pointer address and doesn't free the memory of
** the link’s content, then frees the link’s memory using free(). Finally, the
** pointer to the link that was just freed set to NULL.
*/
void			ft_lstdelone_ic(t_list **alst);
/*
** Takes as a parameter the adress of a pointer to a link and frees the memory
** of this link and every successors of that link using the functions del and
** free(). 
**  The pointer to the link that was just freed must be set to
** NULL.
*/
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
/*
** Takes as a parameter the adress of a pointer to a link and frees the memory
** of this link and every successors of that link using the function free()
** ignoring content. 
** Finally the pointer to the link that was just freed must be set to NULL.
*/
void			ft_lstdel_ic(t_list **alst);
/*
** Adds the element new at the beginning of the list.
*/
void			ft_lstadd(t_list **alst, t_list *new);
/*
** Iterates the list lst and applies the function f to each link.
*/
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
/*
** Iterates a list lst and applies the function f to each link to create a
** “fresh” list (using malloc(3)) resulting from the successive applications of
** f. If the allocation fails, the function returns NULL.
*/
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** Additional functions
*/

#endif
