# encoding: UTF-8

Dir.chdir "boolinq"
HeaderFile = Struct.new(:name, :links, :content)

include_std = [];
file_list = [];

for file in Dir.glob("*.h")
    #puts "Processing file #{file} ..."
    
    links = [];
    content = [];
    for line in File.open(file, "r")
        if line.start_with?("#include <")
            include_std << line
        elsif line.start_with?("#include \"")
            links << line[10..-3]
        elsif line.start_with?("#pragma once")
            
        else
            content << line
        end
    end
    
    file_list << HeaderFile.new(file,links,content)
end

# Rearrange files

index = 0
for file in file_list
    max_index = index
    for link in file.links
        tmp_index = 0
        for f in file_list
            if f.name == link
                break;
            end;
            tmp_index += 1
        end
        
        max_index = [max_index, tmp_index].max
    end
    
    if index != max_index
        tmp = file_list[index]
        file_list[index] = file_list[max_index]
        file_list[max_index] = tmp
    end
    
    index += 1
end

# Output to single file

Dir.chdir ".."
ofile = File.open("boolinq-all.h", "w")
ofile.puts "#pragma once"
ofile.puts
include_std.sort_by!{|a| a.size}
for inc in include_std
    ofile.puts inc
end
for file in file_list
    ofile.puts file.content
end