/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 00:44:51 by andeviei          #+#    #+#             */
/*   Updated: 2023/09/18 17:46:55 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

int		ft_tolower(int c);
int		ft_toupper(int c);

void	ft_bzero(void *str, size_t len);
void	*ft_memchr(const void *mem, int c, size_t len);
int		ft_memcmp(const void *mem1, const void *mem2, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t len);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	*ft_memset(void *mem, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);

char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *str);
void	ft_striteri(const char *str, void (*fun)(unsigned int, char*));
char	*ft_strjoin(const char *str1, const char *str2);
size_t	ft_strlcat(const char *dest, const char *src, size_t len);
size_t	ft_strlcpy(const char *dest, const char *src, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strmapi(const char *str, char (*fun)(unsigned int, char));
int		ft_strncmp(const char *str1, const char *str2, size_t len);
char	*ft_strnstr(const char *h, const char *n, size_t len);
char	*ft_strrchr(const char *str, int c);
char	*ft_strtrim(const char *str, const char *charset);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	**ft_split(const char *str, char c);
int		ft_atoi(const char *str);
char	*ft_itoa(int num);

void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *str, int fd);
void	ft_putnbr_fd(int num, int fd);
void	ft_putstr_fd(char *str, int fd);

void	ft_lstadd_back(t_list **lst, t_list *n);
void	ft_lstadd_front(t_list **lst, t_list *n);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*fun)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*fun)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

#endif