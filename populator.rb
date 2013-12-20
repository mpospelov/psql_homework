require 'active_record'
require 'populator'
require 'time'
require 'byebug'
require 'faker'

ActiveRecord::Base.establish_connection(adapter: "postgresql", username: "postgres", password: "bqov7cv9y9", database: "rgr_db")

class Achivement < ActiveRecord::Base
end

class AchivementsTeachers < ActiveRecord::Base
end

class Authorship < ActiveRecord::Base
end

class ConferencesTeacher < ActiveRecord::Base
end

class Conference < ActiveRecord::Base
end

class Discipline < ActiveRecord::Base
end

class DisciplinesTeacher < ActiveRecord::Base
end

class Publication < ActiveRecord::Base
end

class ScientificManagement < ActiveRecord::Base
end

class Teacher < ActiveRecord::Base
end

p_count = 3
Achivement.populate(p_count) do |a|
  a.name = Populator.words(1..3) 
  a.description = Faker::Lorem.paragraph(1)
  a.topicality = [true, false].shuffle.first
end

Conference.populate(p_count) do |c|
  c.date = Time.at(rand * Time.now.to_i).to_date
  c.theme = Populator.words(1..3)
  c.place = Faker::Address.street_address
  c.type = ["Международная", "Межвузовская", "Региональная"].shuffle.first
end

Discipline.populate(p_count) do |d|
  d.id = rand(1000000)
  d.name = Populator.words(1..3)
  d.hours = rand(200)
end

Teacher.populate(p_count) do |t|
  t.name = Faker::Name.name
  t.title = ["Доцент", "Профессор", "Без звания"].shuffle.first
  t.post = ["Доцент", "Ассистент", "Зам. декана", 
            "Профессор", "Зав. кафедры", "Специалист"].shuffle.first
end

Publication.populate(p_count) do |p|
  p.name = Populator.words(1..3)
  p.house = Populator.words(1..3)
  p.date = Time.at(rand * Time.now.to_i).to_date
  p.page_count = rand(1000)
  p.circulation = rand(100000)
end

ScientificManagement.populate(p_count) do |cm|
  cm.student_name = Faker::Name.name
  cm.teacher_name = Teacher.all.pluck(:name).shuffle.first
  cm.theme = Populator.words(1..3)
  cm.type = ["Курсовая", "Дипломная", "Кандидатская", "Докторская"]
end

AchivementsTeachers.populate(p_count) do |instance|
  instance.achivement_name = Achivement.all.pluck(:name).shuffle.first
  instance.teacher_name = Teacher.all.pluck(:name).shuffle.first
  instance.date = Time.at(rand * Time.now.to_i).to_date
end

Authorship.populate(p_count) do |instance|
  instance.publication_name = Publication.all.pluck(:name).shuffle.first
  instance.teacher_name = Teacher.all.pluck(:name).shuffle.first
end

ConferencesTeacher.populate(p_count) do |instance|
  c = Conference.unscoped.select(:date, :theme).shuffle.first
  instance.conference_date = c.date
  instance.conference_theme = c.theme
  instance.teacher_name = Teacher.all.pluck(:name).shuffle.first
end

DisciplinesTeacher.populate(p_count) do |instance|
  instance.discipline_id = Discipline.pluck(:id).shuffle.first
  instance.teacher_name = Teacher.pluck(:name).shuffle.first
end
