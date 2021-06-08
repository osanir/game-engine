# TODO: Read json data from file.
json_string = """
{"compressionlevel":-1,"height":17,"infinite":false,"layers":[{"data":[24,92,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,134,93,24,113,36,37,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,23,24,113,58,59,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,23,24,113,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,23,24,113,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,23,24,113,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,23,24,113,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,35,23,24,113,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,8,8,9,23,92,135,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,29,30,30,31,23,113,7,8,8,8,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,29,30,30,31,23,113,29,30,30,30,31,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,29,30,30,31,23,113,29,30,30,30,31,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,29,30,30,31,23,113,29,30,30,30,31,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,35,29,30,30,31,23,113,29,30,16,32,8,8,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,8,8,8,33,30,30,35,23,113,51,35,60,52,35,30,7,8,9,0,0,0,0,0,0,0,0,0,0,7,8,8,33,30,30,30,30,30,36,37,23,114,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,51,52,52,52,52,52,52,52,52,58,59,23,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,26,2,2,2,2,2,2,2,2,2,2,2,23],"height":17,"id":1,"name":"Desen Katmanı 1","opacity":1,"type":"tilelayer","visible":true,"width":32,"x":0,"y":0}],"nextlayerid":2,"nextobjectid":1,"orientation":"orthogonal","renderorder":"left-up","tiledversion":"1.7.0","tileheight":16,"tilesets":[{"firstgid":1,"source":"../Terrain (16x16).tsx"}],"tilewidth":16,"type":"map","version":"1.6","width":32}
"""

import json
data = json.loads(json_string)

name = data["layers"][0]["name"]
renderorder = data["renderorder"]
tilewidth = data["tilewidth"]
tileheight = data["tileheight"]
mapheight = data["layers"][0]["height"]
mapwidth = data["layers"][0]["width"]

print("Name: ", name)
print("Render order: ", renderorder)
print("Tile width: ", tilewidth)
print("Tile height: ", tileheight)
print("Map height: ", mapheight)
print("Map width: ", mapwidth)

mapData = data["layers"][0]["data"];


mapFile = open("map.txt",'w')
for i in range(0, len(mapData)):
	if i % mapwidth == 0 and i != 0:
		mapFile.write("-2\n")
	mapFile.write(str(mapData[i]) + " ")
mapFile.write("-2")
mapFile.close()
print("Succesfully exported!")
#print(mapData)

#print(json.dumps(data))