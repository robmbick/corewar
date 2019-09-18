/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2019/09/16 14:41:48 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

t_op			g_op[17] =
{
	{
		.name = NULL,
		.code = 0,
		.num_arg = 0,
		.is_args_types = 0,
		.args_types = {0 | 0 | 0},
		.dir_size = 0,
		.wait = 0
	},
	{
		.name = "live",
		.code = 0x01,
		.num_arg = 1,
		.is_args_types = 0,
		.args_types = {T_DIR | 0 | 0},
		.dir_size = 4,
		.wait = 10
	},
	{
		.name = "ld",
		.code = 0x02,
		.num_arg = 2,
		.is_args_types = 1,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.dir_size = 4,
		.wait = 5
	},
	{
		.name = "st",
		.code = 0x03,
		.num_arg = 2,
		.is_args_types = 1,
		.args_types = {T_REG, T_REG | T_IND, 0},
		.dir_size = 4,
		.wait = 5
	},
	{
		.name = "add",
		.code = 0x04,
		.num_arg = 3,
		.is_args_types = 1,
		.args_types = {T_REG, T_REG, T_REG},
		.dir_size = 4,
		.wait = 10
	},
	{
		.name = "sub",
		.code = 0x05,
		.num_arg = 3,
		.is_args_types = 1,
		.args_types = {T_REG, T_REG, T_REG},
		.dir_size = 4,
		.wait = 10
	},
	{
		.name = "and",
		.code = 0x06,
		.num_arg = 3,
		.is_args_types = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.dir_size = 4,
		.wait = 6
	},
	{
		.name = "or",
		.code = 0x07,
		.num_arg = 3,
		.is_args_types = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.dir_size = 4,
		.wait = 6
	},
	{
		.name = "xor",
		.code = 0x08,
		.num_arg = 3,
		.is_args_types = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.dir_size = 4,
		.wait = 6
	},
	{
		.name = "zjmp",
		.code = 0x09,
		.num_arg = 1,
		.is_args_types = 0,
		.args_types = {T_DIR, 0, 0},
		.dir_size = 2,
		.wait = 20
	},
	{
		.name = "ldi",
		.code = 0x0A,
		.num_arg = 3,
		.is_args_types = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.dir_size = 2,
		.wait = 25
	},
	{
		.name = "sti",
		.code = 0x0B,
		.num_arg = 3,
		.is_args_types = 1,
		.args_types = {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
		.dir_size = 2,
		.wait = 25
	},
	{
		.name = "fork",
		.code = 0x0C,
		.num_arg = 1,
		.is_args_types = 0,
		.args_types = {T_DIR, 0, 0},
		.dir_size = 2,
		.wait = 800
	},
	{
		.name = "lld",
		.code = 0x0D,
		.num_arg = 2,
		.is_args_types = 1,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.dir_size = 4,
		.wait = 10
	},
	{
		.name = "lldi",
		.code = 0x0E,
		.num_arg = 3,
		.is_args_types = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.dir_size = 2,
		.wait = 50
	},
	{
		.name = "lfork",
		.code = 0x0F,
		.num_arg = 1,
		.is_args_types = 0,
		.args_types = {T_DIR, 0, 0},
		.dir_size = 2,
		.wait = 1000
	},
	{
		.name = "aff",
		.code = 0x10,
		.num_arg = 1,
		.is_args_types = 1,
		.args_types = {T_REG, 0, 0},
		.dir_size = 4,
		.wait = 2
	}
};


t_op1    op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};
