import sys

def compress(old_str):
	new_str = ""
	print "old str:", old_str
	i = 0
	while i < len(old_str):
		j = i+1
		count = 1
		while j < len(old_str) and old_str[j] == old_str[i]:
			j += 1
			count += 1
		new_str += old_str[i] + str(count)
		i = j
	print "new str:", new_str
	if len(new_str) >= len(old_str):
		print "do not compress"

if __name__ == '__main__':
	args = sys.argv
	if len(args) == 2:
		compress(args[1])
	else:
		compress("hellowolrd")
	# compress