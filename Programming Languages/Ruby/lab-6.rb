## Шаблон для выполнения заданий Лабораторной работы №6 
## ВСЕ КОММЕНТАРИИ ПРИВЕДЕННЫЕ В ДАННОМ ФАЙЛЕ ДОЛЖНЫ ОСТАТЬСЯ НА СВОИХ МЕСТАХ
## НЕЛЬЗЯ ПЕРЕСТАВЛЯТЬ МЕСТАМИ КАКИЕ-ЛИБО БЛОКИ ДАННОГО ФАЙЛА
## решения заданий должны быть вписаны в отведенные для этого позиции 

################################################################################
# Задание 1 
# add b
class Array
  def add b
    (self.zip b).map {|x| x.reduce(:+)}
  end
end
################################################################################

# конец описания задания 1
################################################################################

################################################################################
# Задания 2-6 
# Класс Field
################################################################################
class Field
  FieldSize = 10

  def initialize
    @field = Array.new(FieldSize) {Array.new(FieldSize)}
  end
  # Задание 3 size (метод класса)
  def self.size
    FieldSize
  end
  # Задание 4 set!(n, x, y, hor, ship)
  def set!(n, x, y, hor, ship = nil)
    if hor
      (x .. x + n - 1).each {|i| @field[i][y] = ship}
    else
      (y .. y + n - 1).each {|i| @field[x][i] = ship}
    end
  end

  # Задание 5 print_field
  def print_field
    print "+"
    (1 .. FieldSize).each {|_| print "-"}
    print "+\n"
    (0 .. FieldSize - 1).each {|i| 
      print "|"
      (0 .. FieldSize - 1).each {|j| 
        if @field[i][j].nil?
          print " "
        else
          print @field[i][j].to_s
        end
      }
      print "|\n"
    }
    print "+"
    (1 .. FieldSize).each {|_| print "-"}
    print "+\n"
  end

  # Задание 6 free_space?(n, x, y, hor, ship)
  def free_space?(n, x, y, hor, ship)
    true
  end
end
# конец описания класса Field
################################################################################


################################################################################
# Задания 7-16 
# Класс Ship
################################################################################
class Ship
  attr_reader :len 
  attr_reader :coord

  def initialize (field, len)
    @len = len
    @myfield = field
    @maxhealth = 100 * len
    @minhealth = 30 * len
    @health = @maxhealth
  end

  # Задание 8 to_s
  def to_s
    "X"
  end

  # Задание 9 clear
  def clear
    @myfield.set!(@len, @coord[0], @coord[1], @hor)
  end

  # Задание 10 set!(x, y, hor)
  def set!(x, y, hor)
    if @myfield.free_space?(@len, x, y, @hor, self)
      if not @coord.nil?
        clear
      end
      @coord = Array.new(@len)
      @coord[0] = x
      @coord[1] = y
      if hor
        @coord[2] = x + @len - 1
        @coord[3] = y
      else
        @coord[2] = x
        @coord[3] = y + @len - 1
      end
      @myfield.set!(@len, x, y, hor, self)
      @hor = hor
      true
    else
      false
    end
  end

  # Задание 11 kill
  def kill
    clear
    @coord = nil
  end

  # Задание 12 explode
  def explode
    @health -= 70
    if @health <= @minhealth
      kill
      @len
    else
      nil
    end
  end

  # Задание 13 cure
  def cure
    @health += 30
    if @health > @maxhealth
      @health = @maxhealth
    end
  end

  # Задание 14 health
  def health
    (100 * @health / @maxhealth).round(2)
  end

  # Задание 15 move(forward)

  # Задание 16 rotate(n, k)
end
# конец описания класса Ship
################################################################################

################################################################################
# Задания 17-25
# Класс BattleField
################################################################################

  # Задание 18 fleet

  # Задание 19 place_fleet pos_list

  # Задание 20 remains

  # Задание 21 refresh

  # Задание 22 shoot c

  # Задание 23 cure

  # Задание 24 game_over?

  # Задание 25 move l_move

# конец описания класса BattleField
################################################################################


################################################################################
# Задания 26-31
# Класс Player
################################################################################

  # Задание 27 random_point

  # Задание 28 place_strategy ship_list

  # Задание 29 hit message
  #            miss

  # Задание 30 shot_strategy
  def shot_strategy
    if @manual
      @lastshots.each {|x| print(x, "\n")}
      puts "Make a shot. To switch off the manual mode enter -1 for any coordinate"
      while true
        print "x = "; x = gets.to_i; print x
        print " y = "; y = gets.to_i; puts y
        shot = [x,y]
        if shot.all? {|a| a.between?(-1, Field.size - 1)}
          break
        else
          puts "Incorrect input"
        end
      end
      if shot.any? {|a| a == -1}
        @manual = false
        shot_strategy
      else
        @shot = shot
      end
    else
      # Здесь необходимо разместить решение задания 30

      # конец решения задания 30
    end
  end

  # Задание 31 ship_move_strategy remains
  def ship_move_strategy remains
    if @manual
      puts "Ship health"
      tmp_field = Field.new
      names = ("0".."9").to_a + ("A".."Z").to_a + ("a".."z").to_a
      ship_hash = {}
      remains.each do |ship|
        name = names[ship[0]]
        x = ship[1][0]; y = ship[1][1]
        hor = (ship[1][1] == ship[1][3])
        ship_hash[name] = [ship[0], ship[2]]
        tmp_field.set!(ship[2], x, y, hor, name)
        print(name, " - ", ship[3], "%\n") 
      end
      puts "Your ships"
      tmp_field.print_field
      puts "Make a move. To switch off the manual mode enter an incorrect ship name"
      while true
        print "Choose ship: "; 
        name = gets.strip; puts name
        if !ship_hash[name] then break end
        move = 0
        begin
          print "Enter 0 to move, 1-3 to rotate: " 
          move = gets.to_i; puts move
        end until move.between?(0,3)
        if move == 0
          print "1 - forward/any - backward): "; dir = gets.to_i
          puts dir
        else
          dir = 0
          begin
            print "Choose a center point: (1..#{ship_hash[name][1]}): "
            dir = gets.to_i; puts dir
          end until dir.between?(1,ship_hash[name][1])
        end
        break
      end
      if !ship_hash[name]
        @manual = false
        ship_move_strategy remains
      else
        [ship_hash[name][0], move, dir]
      end
    else
      # Здесь необходимо разместить решение задания 31
      
      # конец решения задания 31
    end
  end 


# конец описания класса Player
################################################################################

################################################################################
# Задания 32-33 
# Класс Game
################################################################################

  # Задание 33 start

# конец описания класса Game
################################################################################

################################################################################
# Переустановка датчика случайных чисел
################################################################################
srand
################################################################################

#№ Пример запуска
# p1 = Player.new("Ivan",true)
# p2 = Player.new("Feodor")
# g = Game.new(p1,p2)
# g.start

