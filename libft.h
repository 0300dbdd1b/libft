/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noaddino <noaddino@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:37:14 by noaddino          #+#    #+#             */
/*   Updated: 2025/04/17 23:38:21 by noaddino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>	// size_t
# include <unistd.h>	// write
# include <stdlib.h>	// malloc, free
# include <stdarg.h>	// va_args
# include <fcntl.h>		//open
# ifndef OPEN_MAX
#  define OPEN_MAX _SC_OPEN_MAX
# endif

// ---------- Partie 1 : Fonctions Libc ----------
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);

// ---------- Partie 2 : Fonctions supplémentaires ----------
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// ---------- Partie Bonus : Listes chaînées ----------
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

# define BASE10		"0123456789"
# define BASE16LOW	"0123456789abcdef"
# define BASE16UP	"0123456789ABCDEF"

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr_base_unsigned(unsigned long nbr, const char *base);
int		ft_puthex(long long int nbr, int uppercase);
int		ft_putptr(void *ptr);
int		ft_printf(const char *str, ...);
int		ft_putnbr(int n);
int		ft_putnbr_unsigned(unsigned int n);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	128
# endif

char	*get_next_line(int fd);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strcat(char *dest, const char *src);

typedef struct s_memheader
{
	size_t	size;
}	t_memheader;

void	*ft_malloc(size_t size);
void	ft_free(void *ptr);
void	*ft_realloc(void *ptr, size_t new_size);
size_t	ft_get_malloc_size(void *ptr);

typedef struct s_lazy_allocator_segment
{
	void							*ptr;
	struct s_lazy_allocator_segment	*next;
}	t_seg;
typedef t_seg	t_lazy_allocator;
t_seg	*create_lazy_allocator_segment(size_t size);
void	*allocate_from_lazy_allocator(t_seg **allocator, size_t size);
void	free_from_lazy_allocator(t_seg **allocator, void *ptr);
void	free_lazy_allocator(t_seg **allocator);
#endif
