/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:09:05 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/23 10:58:10 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

# define BASE_L "0123456789abcdef"
# define BASE_U "0123456789ABCDEF"

size_t			ft_pf_putnbr_hex(unsigned int n, char *base);
size_t			ft_pf_putchar(char c);
size_t			ft_pf_putnbr(int n);
size_t			ft_pf_putnbr_ui(unsigned int n);
int				ft_printf(const char *str, ...);
size_t			select_formats(va_list args, char **format);
size_t			ft_pf_putstr(char *s);
size_t			analize_flags(va_list args, char **format, size_t numb_char);
size_t			hash_flag(va_list args, char **format, \
size_t numb_char);
size_t			put_sign(va_list args, char **format, size_t numb_char);
size_t			handle_zero(va_list args, char **format, \
size_t numb_char);
unsigned int	count_decimal(int nbr);
size_t			handle_dash(va_list args, char **format, \
size_t numb_char);
size_t			handle_empty_space(va_list args, char **format, \
size_t numb_char);
size_t			handle_dot(va_list args, char **format, \
size_t numb_char);
int				ft_pf_atoi(char *str);
size_t			ft_strlen(const char *str);
size_t			field_size(char **format);
size_t			check_with(char **format);
size_t			ft_pf_putchar_fw(char c, size_t field_len);
size_t			select_formats_with_field(va_list args, char **format, \
size_t numb_char, size_t field_len);
size_t			ft_pf_putstr_fw(char *s, size_t field_len, size_t numb_char);
size_t			ft_pf_putnbr_hex_fw(unsigned int n, char *base, \
size_t field_len);
size_t			ft_pf_putnbr_p_fw(unsigned long n, char *base, \
size_t field_len);
size_t			ft_pf_putnbr_fw(int n, size_t field_len);
size_t			ft_pf_putnbr_ui_fw(unsigned int n, size_t field_size);
size_t			analize_flags_fw(va_list args, char **format, \
size_t numb_char);
size_t			handle_dot_fw(char *str, char **format, size_t numb_char, \
size_t field_len);
size_t			ft_pf_putnbr_p(unsigned long n, char *base);
size_t			analize_dot_fw(va_list args, size_t numb_char, char **format, \
size_t field_len);
unsigned int	count_decimal(int nbr);
void			go_foward_array(char **array, size_t numb);
size_t			ft_pf_putstr_dot(va_list args, size_t numb_char, size_t len);
size_t			ft_putnbr_hex_dot(unsigned int n, size_t numb_char, \
size_t n_zeros, char *base);
size_t			ft_pf_putnbr_ui_dot(unsigned int n, size_t field_len);
size_t			ft_pf_putnbr_dot(int n, size_t field_len);
size_t			handle_dot_hash(unsigned int nbr, char **format, \
size_t numb_char);
size_t			putnbr_hash_fw_dot(unsigned long n, char **format, \
size_t numb_char, size_t len);
size_t			ft_pf_putnbr_hash_fw(va_list args, char **format, \
size_t numb_char);
size_t			ft_pf_putnbr_hash_hex_fw2(unsigned int n, char *base, \
size_t field_len, char c);
size_t			handle_dot2(va_list args, char **format, size_t nb_ch, \
size_t len);
size_t			handle_dash_hash(va_list args, char **format, \
size_t numb_char);
size_t			putnbr_hash_dash_dot(unsigned long n, char **format, \
size_t numb_char, size_t len);
size_t			handle_field(va_list args, char **format, size_t nb_ch);
size_t			put_sign_d(int n, size_t numb_char);
void			*pf_bzero(void *ptr, size_t n);
size_t			ft_pf_putnbr_hex_fwb(char *str, size_t field_len);
size_t			ft_pf_putnbr_p_fw3(char *str, size_t field_len);
size_t			ft_pf_putnbr_fw2(int n, size_t field_len, size_t i, \
char *array);
size_t			ft_pf_putnbr_dot2(int n, size_t field_len, \
char *array, size_t i);
size_t			ft_pf_putnbr_hash_hex_fw2b(char *str, size_t field_len, \
char c);
size_t			ft_pf_putnbr_hash_hex_dash(unsigned int n, char *base, \
size_t field_len, char c);
size_t			ft_pf_putnbr_hash_hex_dashb(char *str, size_t field_len, \
char c);
size_t			ft_pf_fw_dot_s(char *str, size_t len, size_t field_len);
size_t			ft_pf_fw_dot_hex(unsigned int n, size_t len, \
size_t field_len, char *base);
size_t			len_is_big(size_t field_len, size_t len, size_t i);
size_t			ft_pf_fw_dot(int i, size_t len, size_t field_len);
size_t			ft_pf_fw_dotb(size_t i, size_t len, size_t field_len, int nb);
size_t			ft_pf_fw_dot_ub(size_t i, size_t len, size_t field_len);
size_t			ft_pf_fw_dot_u(unsigned int nb, size_t len, size_t field_len);
size_t			ft_pf_fw_dotneg(size_t i, size_t len, size_t field_len, int nb);
size_t			handle_dashb(va_list args, char **format, size_t nb_ch, \
size_t f_len);
size_t			ft_pf_putchar_dash(char c, size_t field_len);
size_t			ft_pf_putstr_dash(char *s, size_t field_len, size_t numb_char);
size_t			ft_pf_putnbr_p_dash(unsigned long n, char *base, \
size_t field_len);
size_t			ft_pf_putnbr_p_dash2(char *str, size_t field_len);
size_t			ft_pf_putnbr_dash(int n, size_t field_len);
size_t			ft_pf_putnbr_dash2(int n, size_t field_len, size_t i, \
char *array);
size_t			ft_pf_putnbr_ui_dash(unsigned int n, size_t field_len);
size_t			ft_pf_putnbr_hex_dash(unsigned int n, char *base, \
size_t field_len);
size_t			ft_pf_putnbr_hex_dashb(char *str, size_t field_len);
size_t			handle_dash_dot(va_list args, size_t numb_char, char **format, \
size_t field_len);
size_t			ft_pf_dash_dot(int nb, size_t len, size_t field_len);
size_t			ft_pf_dash_dotb(size_t i, size_t len, int nb);
size_t			ft_pf_dash_dotneg(size_t i, size_t len, int nb);
size_t			ft_pf_dash_dot_s(char *str, size_t len, size_t field_len);
size_t			ft_pf_dash_dot_u(unsigned int nb, size_t len, size_t field_len);
size_t			ft_pf_dash_dot_ub(size_t i, size_t len);
size_t			ft_pf_dash_dot_uc(size_t i, size_t len, size_t field_len);
size_t			ft_pf_dash_dot_hex(unsigned int n, size_t len, \
size_t field_len, char *base);
size_t			len_is_big_dash(size_t len, size_t i);
size_t			ft_pf_dash_dotc(size_t i, size_t len, size_t field_len, \
int nb);
size_t			ft_pf_putnbr_empty(int n);
size_t			handle_dot_hash(unsigned int nbr, char **format, \
size_t numb_char);
size_t			ft_putnbr_hex_hash_dot(unsigned int n, size_t dash_len, \
size_t n_zeros, char *base);
size_t			ft_putnbr_hex_hash_dotb(char *str, size_t dash_len, \
size_t n_zeros);
size_t			ft_pf_fw_dot_sb(size_t numb_char, size_t str_len, \
size_t field_len);
size_t			ft_pf_fw_dotc(size_t i, size_t len, size_t field_len, \
int nb);
size_t			str_null(size_t field_len);
size_t			pointer_nill(size_t field_len);
size_t			ft_pf_putnbr_hex_dashc(size_t field_len);
size_t			u_negative(size_t field_size, size_t len);
size_t			elses(va_list args, char **format, size_t numb_char);
size_t			d_zero(va_list args, size_t numb_char, size_t f_len);
size_t			str_null_dash(size_t field_len, size_t numb_char);
size_t			str_null_dash_dot(size_t field_len, size_t numb_char, \
size_t len);
size_t			str_null_fw_dot(size_t field_len, size_t numb_char, \
size_t len);
size_t			hex_zero_fw(size_t numb_char, size_t field_len);
size_t			p_isnull_dash(char *str, size_t field_len, \
size_t numb_char);
size_t			d_zero2(int i, size_t numb_char, size_t f_len);
size_t			ft_putnbr_hex_fw_dot(unsigned int n, size_t len, \
size_t dot_len, char c);
size_t			put_sign_dot(va_list args, size_t numb_char, \
char **format);
size_t			put_sign_fw(va_list args, size_t numb_char, char **format);
size_t			ft_pf_putnbr_sign_fw(int n, size_t field_len);
size_t			ft_pf_putnbr_sign_fw2(int n, size_t field_len, size_t i, \
char *array);
size_t			put_sign_fw_dot(va_list args, size_t numb_char, char **format, \
size_t f_len);
size_t			ft_pf_sign_fw_dot(int nb, size_t len, size_t field_len, \
size_t numb_char);
size_t			ft_pf_sign_fw_dotb(size_t i, size_t len, size_t field_len, \
int nb);
size_t			ft_pf_putnbr_sign_dot(va_list args, size_t numb_char, \
size_t dot_len);
size_t			ft_putnbr_hex_fw_dotb(int i, size_t len, size_t dot_len, \
char c);
size_t			ft_putnbr_hex_fw_dotc(int i, size_t dot_len, size_t numb_char);
size_t			ft_putnbr_hex_fw_dotd(int i, int *array, size_t numb_char, \
char c);
int				ft_printf(const char *str, ...);
#endif
