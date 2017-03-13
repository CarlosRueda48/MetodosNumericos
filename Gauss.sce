//Modificar A y B respectivamente para resolver los sistemas.
A = [5,-2,3;4,-4,1;-1,6,2;]; //Matriz creada a partir de coeficientes del sistema de ecuaciones
B = [2; 5; 1;]; //Matriz de constantes de ecuaciones lineales

n = length(B);

Aug = [A,B];

for j = 1:n-1
    for i = j+1:n
        Aug(i,j:n+1) = Aug(i,j:n+1) - Aug(i,j) /Aug(j,j) * Aug(j,j:n+1);
    end
end

z = zeros(n,1);
z(n)=Aug(n,n+1) / Aug(n,n);
for i = n-1:-1:1
    z(i) = (Aug(i,n+1)-Aug(i,i+1:n)*z(i+1:n))/Aug(i,i);
end

//Este paso se puede automatizar, si no, modificar para hacer n prints.
disp(strcat(["x = ", string(z(1))]))
disp(strcat(["y = ", string(z(2))]))
disp(strcat(["z = ", string(z(3))]))
disp(strcat(["z = ", string(z(4))]))
    
