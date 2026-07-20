/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarcia- <ugarcia-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 09:28:34 by ugarcia-          #+#    #+#             */
/*   Updated: 2026/07/20 07:58:31 by ugarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/** Concatena string segura -> Pega 'src' al final de 'dst' con '\\0'.
 * Devuelve long inicial de 'dst' + long de 'src'.*/
size_t	ft_strlcat(char *dst, const char *src, size_t size);
/** String a Int -> Convierte " -42" en el entero -42.*/
long int		ft_atol(const char *nptr);
/** Borra memoria -> Llena de ceros ('\\0') 'n' bytes de 's'. Devuelve nada.*/
void	ft_bzero(void *s, size_t n);
/** Reserva y limpia -> Reserva memoria con malloc y la llena de ceros.
 * Devuelve puntero o NULL.*/
void	*ft_calloc(size_t nmemb, size_t size);
/** ¿Es letra o número? -> Devuelve 1 (sí) o 0 (no).*/
int		ft_isalnum(int c);
/**¿Es letra? -> Devuelve 1 (sí) o 0 (no).*/
int		ft_isalpha(int c);
/** ¿Está en la tabla ASCII? (0-127) -> Devuelve 1 (sí) o 0 (no).*/
int		ft_isascii(int c);
/** ¿Es número? (0-9) -> Devuelve 1 (sí) o 0 (no).*/
int		ft_isdigit(int c);
/** ¿Es un carácter imprimible? (incluye espacio) -> Devuelve 1 (sí) o 0 (no).*/
int		ft_isprint(int c);
/** Busca en memoria -> Busca 'c' en los primeros 'n' bytes de 's'.
 * * Devuelve puntero al byte o NULL.*/
void	*ft_memchr(const void *s, int c, size_t n);
/** Compara memoria -> Compara 'n' bytes de 's1' y 's2'.
 * Devuelve <0, 0 (iguales), o >0.*/
int		ft_memcmp(const void *s1, const void *s2, size_t n);
/** Copia memoria -> Copia 'n' bytes de 'src' a 'dest'.
 * Ojo: no maneja solapamiento.
 * Devuelve 'dest'.*/
void	*ft_memcpy(void *dest, const void *src, size_t n);
/** Copia memoria segura -> Igual que memcpy pero
 * maneja solapamiento de forma segura.
 * Devuelve 'dest'.*/
void	*ft_memmove(void *dest, const void *src, size_t n);
/** Llena memoria -> Llena 'n' bytes de 's' con el char 'c'. Devuelve 's'.*/
void	*ft_memset(void *s, int c, size_t n);
/** Busca char adelante -> Busca 'c' en 's' desde el inicio.
 * Devuelve puntero a la primera coincidencia o NULL.*/
char	*ft_strchr(const char *s, int c);
/** Copia string segura -> Copia 'src' en 'dst' metiendo el '\\0'.
 * Devuelve longitud de 'src'.*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
/** Longitud -> Cuenta caracteres de 's' (sin contar el '\\0').
 * Devuelve el total.*/
size_t	ft_strlen(const char *s);
/** Compara strings -> Compara hasta 'n' caracteres.
 * Devuelve <0, 0 (iguales), o >0.*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);
/** Busca substring -> Busca 'little' dentro de 'big' (máximo 'size' bytes).
 * Devuelve puntero al inicio o NULL.*/
char	*ft_strnstr(const char *big, const char *little, size_t size);
/** Busca char atrás -> Busca 'c' en 's' desde el final.
 * Devuelve puntero a la última coincidencia o NULL.*/
char	*ft_strrchr(const char *s, int c);
/** Pasa a minúscula -> Devuelve la minúscula o el mismo char si no es letra.*/
int		ft_tolower(int c);
/** Pasa a MAYÚSCULA -> Devuelve la mayúscula o el mismo char si no es letra.*/
int		ft_toupper(int c);
/** Duplica string -> Hace un malloc exacto y copia 'src'.
 * Devuelve el nuevo string o NULL.*/
char	*ft_strdup(char *src);
/** Corta string -> Crea un trozo de 's' desde
 * el índice 'start' con longitud 'len'.
 * Devuelve el trozo o NULL.*/
char	*ft_substr(char const *s, unsigned int start, size_t len);
/** Junta dos strings -> Une 's1' y 's2' en un string nuevo con malloc.
 * Devuelve el nuevo string o NULL.*/
char	*ft_strjoin(char const *s1, char const *s2);
/** Recorta extremos -> Quita los caracteres de 'set' del principio
 * y final de 's1'.
 * Devuelve el string limpio o NULL.*/
char	*ft_strtrim(char const *s1, char const *set);
/** Separa string -> Trocea 's' usando el char 'c' como separador.
 * Devuelve array de strings terminado en NULL.*/
char	**ft_split(char const *s, char c);
/** Int a String -> Convierte el entero -42 en el string "-42" (con malloc).
 * Devuelve el string o NULL.*/
char	*ft_itoa(int n);
/** Mapea string -> Aplica la función 'f' a cada char de 's'
 * creando un string nuevo.
 * Devuelve el string modificado.*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/** Itera string -> Aplica la función 'f' a cada char de 's'
 * modificando el string original directamente.
 * Devuelve nada.*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
/** Imprime char -> Escribe el carácter 'c' 
 * en el archivo/salida 'fd' (ej: 1 para pantalla).*/
void	ft_putchar_fd(char c, int fd);
/** Imprime string -> Escribe el string 's' en el 'fd'.*/
void	ft_putstr_fd(char *s, int fd);
/** Imprime string + Enter -> Escribe 's' en el 'fd' seguido
 * de un salto de línea ('\\n').*/
void	ft_putendl_fd(char *s, int fd);
/** Imprime número -> Convierte e imprime el entero 'n' en el 'fd'.*/
void	ft_putnbr_fd(int n, int fd);
/** Crea nodo -> Crea un nuevo elemento de lista con el 'content' dado.
 * Devuelve el nodo o NULL.*/
t_list	*ft_lstnew(void *content);
/** Añade al principio -> Inserta el nodo 'new' al inicio de la lista 'lst'.
 * Devuelve nada.*/
void	ft_lstadd_front(t_list **lst, t_list *new);
/** Cuenta nodos -> Cuenta cuántos elementos tiene la lista.
 * Devuelve el número total.*/
int		ft_lstsize(t_list *lst);
/** Último nodo -> Busca el último elemento de la lista.
 * Devuelve puntero a ese nodo o NULL.*/
t_list	*ft_lstlast(t_list *lst);
/** Añade al final -> Inserta el nodo 'new' al final de la lista 'lst'.
 * Devuelve nada.*/
void	ft_lstadd_back(t_list **lst, t_list *new);
/** Borra un nodo -> Aplica 'del' al contenido del nodo 'lst' y
 * libera el nodo (no los siguientes).
 * Devuelve nada.*/
void	ft_lstdelone(t_list *lst, void (*del)(void*));
/** Borra lista entera -> Borra y libera el nodo dado y
 * TODOS sus sucesores usando 'del'.
 * Pone la lista a NULL.*/
void	ft_lstclear(t_list **lst, void (*del)(void*));
/** Itera lista -> Aplica la función 'f' al contenido de cada nodo de la lista.
 * Devuelve nada.*/
void	ft_lstiter(t_list *lst, void (*f)(void *));
/** Mapea lista -> Crea una lista nueva aplicando 'f' al contenido
 * de cada nodo de 'lst'. Si falla,
 * usa 'del'. Devuelve nueva lista.*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
