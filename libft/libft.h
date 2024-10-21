/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:34:25 by nsabia            #+#    #+#             */
/*   Updated: 2024/10/21 16:23:46 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define GARBAGE_COL_SIZE 50
# define GARBAGE_ERROR_EXPAND -2
# define GARBAGE_ERROR_CREATE -1
# define GARBAGE_SUCCESS 0

# include <stdlib.h>
# include <stdbool.h>

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_char_to_str(char c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *s, int c, size_t len);
char	**ft_split(const char *s, char c);
char	*ft_strchr(const char *s, int c);
bool	ft_strchr_str(char *haystack, char *needle);
char	*ft_strdup(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_tab_to_space(const char *str, char *result);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strncpy(char *src, int start, int end);
bool	ft_malloc_str_arr(size_t size, char ***arr);


/* for garbage collector*/
int		*garbage_col_count(void);
void	***garbage_col_get(void);
void	*ft_malloc(size_t size);
int		ft_garbage_col_create(void);
int		ft_garbage_col_add(void *ptr);
void	ft_free(void *ptr);
void	ft_free_all(void);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);

#endif
