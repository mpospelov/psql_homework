require 'active_record'
require 'populator'
require 'time'
require 'byebug'
require 'faker'

ActiveRecord::Base.establish_connection(adapter: "postgresql", username: "postgres", password: "bqov7cv9y9", database: "nastya_rgr")

class Benefit < ActiveRecord::Base
end

class BenefitsTenant < ActiveRecord::Base
end

class House < ActiveRecord::Base
end

class Tenant < ActiveRecord::Base
end

class Flat < ActiveRecord::Base
end

p_count = 3

Benefit.populate(p_count) do |b|
  b.name = Populator.words(1..2)
  b.sum = rand(500..10000)
end

House.populate(p_count) do |h|
  h.address = Faker::Address.street_address
  h.number = rand(1..200)
end

p_count.times do
  flat = Flat.new
  flat.address = House.pluck(:address).shuffle.first
  flat.number = rand(200)
  flat.square = rand(30..200) 
  flat.entrance_number = rand(1..10)
  flat.rent_sum = rand(500..5000)  
  flat.save
end

Tenant.populate(p_count) do |t|
  flat = Flat.select(:address, :number).shuffle.first
  t.name = Faker::Name.name
  t.address = flat.address 
  t.flat_number = flat.number
  t.sex = ["м", "ж"].shuffle.first
  t.age = rand(100)
end

BenefitsTenant.populate(p_count) do |bt|
  bt.benefit_name = "по инвалидности"
  bt.tenant_name = Tenant.all.pluck(:name).shuffle.first
end

