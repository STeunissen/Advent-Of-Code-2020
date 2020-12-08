ids = {
    int(x.translate("".maketrans("FBLR", "0101")), 2)
    for x in [x.strip() for x in open("E:\\Saxion\\Technische Informatica\\Datastructures\\Advent-Of-Code-2020\\Day5\\input.txt").readlines()]
}

print(max(ids))
print(sum(range(min(ids), max(ids) + 1)) - sum(ids))
