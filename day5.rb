# Day 5: A Maze of Twisty Trampolines, All Alike
# http://adventofcode.com/2017/day/5

def part_a(input)
  maze = input.split(/\n/).map(&:to_i)
  pos = 0
  steps = 0
  until pos >= maze.length do
    old = pos
    pos += maze[pos]
    maze[old] += 1
    steps += 1
  end
  steps
end

def part_b(input)
  maze = input.split(/\n/).map(&:to_i)
  pos = 0
  steps = 0
  until pos >= maze.length do
    old = pos
    pos += maze[pos]
    if maze[old] < 3
      maze[old] += 1
    else
      maze[old] -= 1
    end
    steps += 1
  end
  steps
end

