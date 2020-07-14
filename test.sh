# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blinnea <blinnea@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/14 14:28:47 by blinnea           #+#    #+#              #
#    Updated: 2020/07/14 14:28:54 by blinnea          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/zsh
rm -rf test_logs
mkdir -p test_logs test_logs/ko test_logs/ops
for i in {1..$1}; do
	ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`;
	PSOUT=$(./push_swap $ARG);
	CHOUT=$(echo $PSOUT | ./checker $ARG | tr -d '\n');
	WCOUT=$(echo $PSOUT | wc -l | tr -d ' ' | tr -d '\n');
	if [ "$CHOUT" = "KO" ]; then;
		echo $ARG > "test_logs/ko/test_100_$i.log"; fi;
	if (($WCOUT > 700)); then;
		echo "operations: $WCOUT" > "test_logs/ops/test_100_$i.log";
		echo $ARG | tr ' ' '\n' >> "test_logs/ops/test_100_$i.log"; fi;
	ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`;
	PSOUT=$(./push_swap $ARG);
	CHOUT=$(echo $PSOUT | ./checker $ARG | tr -d '\n');
	WCOUT=$(echo $PSOUT | wc -l | tr -d ' ' | tr -d '\n');
	if [ "$CHOUT" = "KO" ]; then;
		echo $ARG > "test_logs/ko/test_500_$i.log"; fi;
	if (($WCOUT > 5500)); then;
		echo "operations: $WCOUT" > "test_logs/ops/test_500_$i.log";
		echo $ARG | tr ' ' '\n' >> "test_logs/ops/test_500_$i.log"; fi;
done;
