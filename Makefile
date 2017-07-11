##
## Makefile for  in /home/leroyc/Delivery/2016/B2/MUL/tekadventure
## 
## Made by Corentin LEROY
## Login   <corentin.leroy@epitech.eu@epitech.net>
## 
## Started on  Wed Apr 12 13:35:45 2017 Corentin LEROY
## Last update Wed Apr 12 13:36:23 2017 Corentin LEROY
##

all:
	make -C lib/printf
	make -C lib/my
	make -C source_files

clean:
	make clean -C lib/printf
	make clean -C lib/my
	make clean -C source_files

fclean:
	make fclean -C lib/printf
	make fclean -C lib/my
	make fclean -C source_files

re:	fclean all
