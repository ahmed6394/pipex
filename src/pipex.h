/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:52:08 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/02 13:53:38 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>

void	run_cmd(char *cmd, char **envp);
void	exit_handler(int exit_code);
void	ft_free_tab(char **tab);
int		open_file(char *file, int mode);
char	*get_env(char *key, char **env);
char	*get_path(char *cmd, char **env);

#endif