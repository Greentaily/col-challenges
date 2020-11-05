#!/bin/bash


help_str="Usage: $0 { --seconds [days] | --height [time] | --pairs [A] [B] }"

pairs() {
  last=0; n=$1
  { [ "$n" -lt 3 ] && n=3; } || { [ $((n % 2)) -eq 0 ] && n=$((n - 1)); };
  for ((n; n<=$2; n=n+2)) do
    is_prime=true
    sup=$(echo "$n" | awk '{print int(sqrt($1))}')
    for ((i=2 ; i<=sup; i++)); do [ $((n % i)) -eq 0 ] && is_prime=false && break; done
    [ "$is_prime" = false ] && continue
    [ $((n - last)) -eq 2 ] && printf "(%s,%s) " "$last" "$n"
    last="$n"
  done
}

[ -z "$2" ] && echo "$help_str" && exit

case $1 in
  --seconds) [ "$2" -gt 0 ] && printf $(($2 * 86400)) || printf 0;;
  --height) awk '{printf ($1 > 0) ? 0.5 * 9.8 * $1 ^ 2 : 0}' <<< "$2";;
  --pairs) { [ -z "$3" ] || [ "$3" -le "$2" ]; } && exit; pairs "$2" "$3" | xargs echo;;
  *) echo "$help_str"
esac
