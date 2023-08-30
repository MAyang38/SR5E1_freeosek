#!/usr/bin/env python

import os
import sys

def find_root():
	p = os.path.abspath(os.getcwd())
	while 1:
		dirs = os.listdir(p)
		for d in dirs:
			if d.endswith(".repo"):
				return p
		p = os.path.abspath(os.path.join(p, '..'))
	return None

def get_gits(p):
	gits = []

	# first, look up for existing file containing the list of gits
	fp = os.path.join(p, ".gits.lst")
	try:
		f = open(fp, "r")
		gl = f.readlines()
		for g in gl:
			gits.append(g.split('\n')[0])
		f.close()
		return gits
	except:
		pass

	for root, dirs, files in os.walk(p):
		if root.find(".repo") != -1:
			continue
		for d in dirs:
			if d.endswith(".git"):
				tmp_d = os.path.join(os.path.join(root, d), "..")
				gits.append(os.path.abspath(tmp_d))
	f = open(fp, "w")
	for g in gits:
		f.write(g + '\n')
	f.close()
	return gits

if len(sys.argv) != 2:
	to_go = ""
else:
	to_go = sys.argv[1]

c = os.path.abspath(os.getcwd())
r = find_root()
if r != None:
	repos = get_gits(r)
	if to_go == "":
		repo_names = []
		for repo in repos:
			repo_names.append(os.path.basename(repo))
		repo_names.sort()
		print("Available git repositories:\n")
		for repo in repo_names:
			print('\t' + repo)
		sys.exit(1)
	for repo in repos:
		if repo.endswith(to_go):
			print(repo)
			sys.exit(0)
