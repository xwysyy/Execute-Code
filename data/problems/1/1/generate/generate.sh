path=$(dirname "$(realpath "$0")")
g++ $path/generator.cpp -o $path/generator -std=c++17
g++ $path/std.cpp -o $path/std

i=0
for row in $(jq -c '.[]' $path/test_data.json)
do
    params=()
    for key in $(echo $row | jq -r 'keys_unsorted | .[]')
    do
        value=$(echo $row | jq -r --arg key "$key" '.[$key]')
        params+=($value)
    done
    $path/generator "${params[@]}" > $path/../cases/$i.in
    $path/std < $path/../cases/$i.in > $path/../cases/$i.out
    ((i++))
    $path/generator "${params[@]}" > $path/../cases/$i.in
    $path/std < $path/../cases/$i.in > $path/../cases/$i.out
    ((i++))
done

rm -f $path/generator $path/std