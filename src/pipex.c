/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:17:57 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/02 16:54:10 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//1. heve to split the command string and execute the command using execve.
//2. have to find correct path 
void	run_cmd(char *cmd, char **envp)
{
	char	**split_cmd;
	char	*path;

	split_cmd = ft_split(cmd, ' ');
	path = get_path(split_cmd[0], envp);
	if (execve(path, split_cmd, envp) == -1)
	{
		ft_putstr_fd("pipex: unable to execute: ", 2);
		ft_putendl_fd(split_cmd[0], 2);
		ft_free_tab(split_cmd);
		exit(127);
	}
}

//handle the parent process here // stdin - read
//open_file function to open the out file or find the error
//if fd is valid dup referse str output 1 else close 1, return -1;
//redirect read end and then close write end as it dont need
void	handle_parent(char **av, int *pipe_fd, char **env)
{
	int	output_fd;

	output_fd = open_file (av[4], 1);
	dup2 (output_fd, 1);
	dup2 (pipe_fd[0], 0);
	close (pipe_fd[1]);
	run_cmd(av[3], env);
}

//child function to handle the child process // stdout- write
//open_file function to open the input file or find the error
//if fd is valid dup referse str input 0 else close 0, return -1;
//redirect write end and then close read end as it dont need
void	handle_child(char **av, int *pipe_fd, char **env)
{
	int	input_fd;

	input_fd = open_file(av[1], 0);
	dup2(input_fd, 0);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[0]);
	run_cmd(av[2], env);
}

// have to hnadle pipe, fork, parent,child, exit	
// if fork return -1, exit -1
// if fork return 0, call child process
// if fork retunr something(pid of child) call parent process.
int	main(int ac, char **av, char **env)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (ac != 5)
		exit_handler(1);
	if (pipe(pipe_fd) == -1)
		exit_handler(2);
	pid = fork();
	if (pid == -1)
		exit_handler(3);
	if (!pid)
		handle_child(av, pipe_fd, env);
	handle_parent(av, pipe_fd, env);
}
