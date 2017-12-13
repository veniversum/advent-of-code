<?php

/*
* Day 4: High-Entropy Passphrases
* http://adventofcode.com/2017/day/4
*/

function partA($in)
{
    return array_sum(array_map('auxPartA', preg_split("/\r\n|\r|\n/", $in)));
}

function partB($in)
{
    return array_sum(array_map('auxPartB', preg_split("/\r\n|\r|\n/", $in)));
}

function auxPartA($str)
{
    $tokens = explode(" ", $str);
    return count($tokens) === count(array_unique($tokens));
}

function auxPartB($str)
{
    $tokens = explode(" ", $str);
    $tokens = array_map(function ($word) {
        $chars = str_split($word);
        sort($chars);
        return implode('', $chars);
    }, $tokens);
    return count($tokens) === count(array_unique($tokens));
}
