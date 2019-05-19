/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 16:27:17 by Edgar             #+#    #+#             */
/*   Updated: 2019/03/17 00:49:54 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <wchar.h>

# include "libft_types.h"
# include "get_next_line.h"
# include "ft_printf.h"

# define BASE "0123456789abcdefghijklmnopqrstuvwxyz"
# define BASE_CAPS "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

# define SH_RED "\e[31m"
# define SH_GREEN "\e[32m"
# define SH_BLUE "\e[34m"
# define SH_YELLOW "\e[33m"
# define SH_DEFAULT "\e[39m"

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_ishexdigit(int c, int uppercase);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strncpy(char *dst, const char *src, size_t len);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strncat(char *s1, const char *s2, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strnstr(const char *h, const char *n, size_t len);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_atoi(const char *str);
int			ft_xatoi(const char *str, char *digits);
t_imax		ft_atoimax(const char *str);
t_umax		ft_atoumax(const char *str);

void		ft_putchar_fd(char c, int fd);
void		ft_putchar(char c);
void		ft_putstr_fd(const char *s, int fd);
void		ft_putstr(const char *s);
void		ft_putendl_fd(const char *s, int fd);
void		ft_putendl(const char *s);
void		ft_putwchar_fd(wchar_t c, int fd);
void		ft_putwchar(wchar_t c);
void		ft_putwstr_fd(wchar_t *s, int fd);
void		ft_putwstr(wchar_t *s);
char		*ft_strjoin(const char *s1, const char *s2);
void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);
char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
void		ft_strclr(char *s);
void		ft_striter(char *s, void (*f)(char*));
void		ft_striteri(char *s, void (*f)(int, char*));
char		*ft_strmap(const char *s, char (*f)(char));
char		*ft_strmapi(const char *s, char (*f)(int, char));
int			ft_strequ(const char *s1, const char *s2);
int			ft_strnequ(const char *s1, const char *s2, size_t n);
char		*ft_strsub(const char *s, t_uint start, size_t len);
char		*ft_strtrim(const char *s);
char		*ft_itoa(long n);
void		ft_putnbr_fd(t_imax n, int fd);
void		ft_putnbr(t_imax n);
void		ft_putunbr_fd(t_umax n, int fd);
void		ft_putunbr(t_umax n);
char		**ft_strsplit(const char *s, char c);

t_list		*ft_lstnew(const void *content, size_t content_size);
void		ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void		ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void		ft_lstadd(t_list **alst, t_list *new);
void		ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

char		*ft_strrev(char *str);
int			ft_isspace(int c);
int			ft_isblankspace(int c);
int			ft_log(t_umax n, int b);
int			ft_pow(int n, int p);
int			ft_index_of_nth(const char *s, char c, int n);
int			ft_index_of(const char *s, char c);
int			ft_nindex_of_nth(const char *s, char c, int n, int max);
int			ft_nindex_of(const char *s, char c, int max);
void		ft_lstappend(t_list **alst, t_list *new);
t_stack		*ft_stknew(const void *content, size_t content_size);
void		ft_stkpush(t_stack **astk, t_stack *new);
t_stack		*ft_stkpop(t_stack *stk);
t_list		*ft_strtolst(const char *s, char c);
void		ft_strshift(char *str, int n);
char		*ft_strscpy(char *dst, const char *src, int s);
void		*ft_realloc(void *ap, size_t size, size_t new_size);
void		ft_strsclr(char *str, int s, int n);
void		ft_lstdelfirst(t_list **lst);

t_matrix	*ft_matadd(t_matrix *a, t_matrix *b);
void		ft_matdel(t_matrix **a);
void		ft_matmult(t_matrix *a, float k);
t_matrix	*ft_matnew(int w, int h);
t_matrix	*ft_matprod(t_matrix *a, t_matrix *b);

void		ft_setbit(t_imax *n, int index);
void		ft_unsetbit(t_imax *n, int index);
int			ft_getbit(t_imax n, int index);
int			ft_getfbit(float n, int index);
int			ft_getfsign(float n);
int			ft_getfexponent(float n);
int			ft_getfmantissa(float n);
int			ft_getfmantissa_dec(float n);
t_umax		ft_abs(t_imax n);
int			ft_min(int a, int b);
int			ft_max(int a, int b);
char		*ft_itoa_base(t_imax n, const t_uint b, const int caps);
char		*ft_utoa_base(t_umax n, const t_uint b, int caps, int s);
t_imax		ft_2_complement(t_imax n);
char		*ft_strins(char **str, char c, int pos);
char		*ft_dtoa(long double n, int p, int s);
char		*ft_strappendchr(char **s, const char c);
char		*ft_strappendstr(char **s, const char *s2);
char		*ft_strnappendstr(char **s, const char *s2, size_t n);
t_str		*ft_tstrappendchr(t_str *s, const char c);
t_str		*ft_tstrappendstr(t_str *s, const char *s2);
t_str		*ft_tstrnappendstr(t_str *s, const char *s2, size_t n);
t_str		*ft_tstrnew(size_t size);
void		ft_puttstr(t_str *s);
void		ft_tstrdel(t_str **s);
char		*ft_wchartostr(wchar_t c);

int			ft_yearisleap(t_uint y);
t_uint		ft_leap_years_between(t_uint a, t_uint b);
t_uint		ft_days_before_month(t_uint m, t_uint y);

#endif
