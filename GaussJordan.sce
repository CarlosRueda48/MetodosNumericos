//Código de Gauss-Jordan.
function [ X ] = gj( A, b )

C=[A b]; //Matriz aumentada
m = length(C(:,1))

for i=1:m
  if C(i,i) ~= 1
      //Se divide la fila entera entre C(i,i)
      C(i,:)= C(i,:) ./ C(i,i);  
  end

  for n=1:m
    if n ~= i
        //Se iguala a cero.
        C(n,:) = -C(n,i) .* C(i,:) + C(n,:); 
    end
  end
end

X = C(:, end);
end  % gj
